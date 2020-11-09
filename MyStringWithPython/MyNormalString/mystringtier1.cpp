#include "mystringtier1.h"


MyStringTier1 & MyStringTier1::operator=(MyString && string)
{
	unsigned int cur_capacity = this->capacity_;
	if (cur_capacity > 1)
	{
		this->Clear();
	}
	if (string.CStr() != nullptr)
	{
		unsigned int size_string = string.Length();
		if (cur_capacity <= size_string + 1)
		{
			cur_capacity = MemoryReAllocation(size_string);
		}
		if (this->string_)
		{
			for (unsigned int i = 0; i < size_string; ++i)
			{
				this->string_[i] = string[i];
			}
			this->string_[size_string] = '\0';
			this->capacity_ = cur_capacity;
		}
	}
	string.~MyString();
	return *this;
}


void MyStringTier1::FromIntToChar(int value, unsigned int count, unsigned int index)
{
	unsigned int rank = 1;
	for (unsigned int i = 1; i < count; i++)
	{
		rank *= 10;
	}
	if (this->string_)
	{
		unsigned int idx = 0;
		if (value < 0)
		{
			this->string_[index + 0] = '-';
			++idx;
			value *= -1;
			++count;
		}
		for (idx; idx < count; ++idx)
		{
			this->string_[index + idx] = value / rank + '0';
			value %= rank;
			rank /= 10;
		}
		this->string_[idx + index] = '\0';
	}
}

int MyStringTier1::BuildMatchingMachine(vector<MyStringTier1> &arr, int number_words, int go_to[MyName::cMaxS][MyName::cMaxC], int out[], int failure_array[])
{
	// Initialize all values in output function as 0. 
	for (unsigned int i = 0; i < MyName::cMaxS; i++)
	{
		out[i] = 0;
	}
	// Initialize all values in goto function as -1. 
	for (unsigned int i = 0; i < MyName::cMaxS; i++)
	{
		for (unsigned int j = 0; j < MyName::cMaxC; j++)
		{
			go_to[i][j] = -1;
		}
	}


	// Initially, we just have the 0 state 
	int states = 1;

	// Construct values for goto function, i.e., fill g[][] 
	// This is same as building a Trie for arr[] 
	for (int i = 0; i < number_words; ++i)
	{
		MyString word = arr[i];
		int currentState = 0;

		// Insert all characters of current word in arr[] 
		for (unsigned int j = 0; j < word.Length(); ++j)
		{
			int ch = word[j] - 'a';

			// Allocate a new node (create a new state) if a 
			// node for ch doesn't exist. 
			if (go_to[currentState][ch] == -1)
				go_to[currentState][ch] = states++;

			currentState = go_to[currentState][ch];
		}

		// Add current word in output function 
		out[currentState] |= (1 << i);
	}

	// For all characters which don't have an edge from 
	// root (or state 0) in Trie, add a goto edge to state 
	// 0 itself 
	for (int ch = 0; ch < MyName::cMaxC; ++ch)
		if (go_to[0][ch] == -1)
			go_to[0][ch] = 0;

	// Now, let's build the failure function 

	// Initialize values in fail function 
	memset(failure_array, -1, sizeof failure_array);

	// Failure function is computed in breadth first order 
	// using a queue 
	queue<int> q;

	// Iterate over every possible input 
	for (int ch = 0; ch < MyName::cMaxC; ++ch)
	{
		// All nodes of depth 1 have failure function value 
		// as 0. For example, in above diagram we move to 0 
		// from states 1 and 3. 
		if (go_to[0][ch] != 0)
		{
			failure_array[go_to[0][ch]] = 0;
			q.push(go_to[0][ch]);
		}
	}

	// Now queue has states 1 and 3 
	while (q.size())
	{
		// Remove the front state from queue 
		int state = q.front();
		q.pop();

		// For the removed state, find failure function for 
		// all those characters for which goto function is 
		// not defined. 
		for (int ch = 0; ch <= MyName::cMaxC; ++ch)
		{
			// If goto function is defined for character 'ch' 
			// and 'state' 
			if (go_to[state][ch] != -1)
			{
				// Find failure state of removed state 
				int failure = failure_array[state];

				// Find the deepest node labeled by proper 
				// suffix of string from root to current 
				// state. 
				while (go_to[failure][ch] == -1)
					failure = failure_array[failure];

				failure = go_to[failure][ch];
				failure_array[go_to[state][ch]] = failure;

				// Merge output values 
				out[go_to[state][ch]] |= out[failure];

				// Insert the next level node (of Trie) in Queue 
				q.push(go_to[state][ch]);
			}
		}
	}

	return states;
}
// Returns the next state the machine will transition to using goto 
// and failure functions. 
// currentState - The current state of the machine. Must be between 
//                0 and the number of states - 1, inclusive. 
// nextInput - The next character that enters into the machine. 
int MyStringTier1::findNextState(int currentState, char nextInput, int go_to[MyName::cMaxS][MyName::cMaxC], int failure_array[])
{
	int answer = currentState;
	int ch = nextInput - 'a';

	// If goto is not defined, use failure function 
	while (go_to[answer][ch] == -1)
		answer = failure_array[answer];

	return go_to[answer][ch];
}

// This function finds all occurrences of all array words 
// in text. 
void MyStringTier1::searchWords(vector <MyStringTier1> &arr, int number_words, int go_to[MyName::cMaxS][MyName::cMaxC], int out[], int failure[])
{
	// Preprocess patterns.
	// Build machine with goto, failure and output functions
	this->BuildMatchingMachine(arr, number_words, go_to, out, failure);

	// Initialize current state
	int currentState = 0;

	// Traverse the text through the nuilt machine to find
	// all occurrences of words in arr[]
	for (unsigned int i = 0; i < this->Length(); ++i)
	{
		currentState = findNextState(currentState, this->string_[i], go_to, failure);

		// If match not found, move to next state
		if (out[currentState] == 0)
			continue;

		// Match found, print all matching words of arr[]
		// using output function.
		for (int j = 0; j < number_words; ++j)
		{
			if (out[currentState] & (1 << j))
			{
				cout << "Word " << arr[j] << " appears from "
					<< i - arr[j].Size() + 1 << " to " << i << endl;
			}
		}
	}
}


int MyStringTier1::FindAhoCorasick(vector<MyStringTier1> &keywords, int number_words)
{

	// OUTPUT FUNCTION IS IMPLEMENTED USING out[] 
// Bit i in this mask is one if the word with index i 
// appears when the machine enters this state. 
	int out[MyName::cMaxS] = { 0 };
	// FAILURE FUNCTION IS IMPLEMENTED USING failure[] 
	int failure[MyName::cMaxS] = { 0 };
	/*the array contains all the transitions of the machine*/
	int go_to[MyName::cMaxS][MyName::cMaxC] = { 0 };

	searchWords(keywords, number_words, go_to, out, failure);
	return 0;

}
MyStringTier1::MyStringTier1(const int value)
{
	unsigned int count = 0;
	int temp = value;
	while (temp != 0)
	{
		temp /= 10;
		++count;
	}
	this->string_ = new char[count + 1];
	if (this->string_)
	{
		this->capacity_ = count + 1;
		if (value == 0)
		{
			this->string_[0] = '\0';
		}
		else
		{
			this->FromIntToChar(value, count, 0);
		}
	}
}


MyStringTier1::MyStringTier1(const float value)
{
	// Extract integer part 
	int ipart = static_cast <int>(value);

	// Extract floating part 
	float fpart = value - static_cast <float>(ipart);
	unsigned int count = 0;
	int temp = ipart;
	while (temp != 0)
	{
		temp /= 10;
		++count;
	}
	unsigned int string_size = count + MyName::cAfterPoint + 2;
	this->string_ = new char[string_size];
	memset(this->string_, 0, string_size);
	if (this->string_)
	{
		this->capacity_ = string_size;
		if (ipart == 0)
		{
			this->string_[0] = '0';
			this->string_[1] = '\0';
		}
		else
		{
			this->FromIntToChar(ipart, count, 0);
		}
		unsigned int size_string = this->Size();
		if (MyName::cAfterPoint != 0 && MyName::cAfterPoint < 10000000)
		{
			this->string_[size_string] = '.';
			++size_string;
			unsigned int rank = 1;
			for (unsigned int i = 1; i < MyName::cAfterPoint; i++)
			{
				rank *= 10;
			}
			fpart *= static_cast <float>(rank);
			temp = static_cast <int>(fpart);
			if (fpart == 0.0)
			{
				this->string_[size_string] = '0';
				this->string_[size_string + 1] = '\0';
				this->capacity_ -= (MyName::cAfterPoint - 1);
			}
			else
			{
				count = 0;
				while (temp != 0)
				{
					temp /= 10;
					++count;
				}
				if (fpart < 0.0)
				{
					fpart *= -1.0;
				}

				this->FromIntToChar(static_cast <int>(fpart), count, size_string);
			}
		}

	}
}

MyStringTier1::MyStringTier1(MyStringTier1 && str)
{
	unsigned int size = str.Length();
	this->string_ = new char[size + 1];
	if (string_)
	{
		this->capacity_ = size + 1;
		for (unsigned int i = 0; i < size; i++)
		{
			this->string_[i] = str.string_[i];
		}
		this->string_[size] = '\0';
	}
	else
	{
		MyStringTier1();
	}
	str.~MyStringTier1();
}
