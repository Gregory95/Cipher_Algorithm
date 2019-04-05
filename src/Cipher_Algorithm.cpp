/*Author:Grigoris Kokozides
 *Data: 16/3/2018
 *References: stackoverflow, cplusplus
 *Programming Assingment 1 - Task 1
 *Some notes: There is no checking for use choice (E-D). If user enter any other
 *character instead of E or D program continues but without doing any Encode or Decode process.
 */

#include <iostream>
#include <string>

using namespace std;

string Encode(int key, string text);
string Decode(int key, string text);

int main()
{
    string input, cipher_text;
    int key;
    char ch; //user choice to encode or decode

    //Welcome Message
    cout <<"Welcome to Ceasar Cipher Algorithm!!" <<endl;
    cout <<"==================================" <<endl<<endl;
    cout <<"Encode - E / Decode - D \n";
    cin >> ch;

    cout <<"Enter your key: ";
    cin >> key;
    while(key < 1)
    {
    	 cout << "You have entered an invalid key. \n";
    	 cout << "Please try again. \n";
    	 cout << "Enter a proper number for the amount of letter shifting: ";
    	 cin >> key;
    }
    cout << "Enter your phrase: ";
    cin.ignore();
    getline(cin, input);
    if(ch == 'E')
      {
        cout <<"Encoding process! \n";
        cipher_text = Encode(key, input);
        cout << "Plain text: " << input<< endl;
        cout << key << ", "<< cipher_text <<endl;
      }
    if(ch == 'D')
      {
        cout <<"Decoding process! \n";
        cipher_text = Decode(key, input);
        cout << "Plain text: " << input<< endl;
        cout << key << ", "<< cipher_text <<endl;
      }

return 0;
}
//Encode
string Encode(int key, string text)
{
		int count, size;
	    //catch the size of the string that user inputs
	    size = (int)text.size();
	    string encodedText = text;
		for (count = 0; count < size; count++)
		    	    {
		    	    	//recognize only characters
		    	        if (isalpha(encodedText[count]))
		    	        {
		    	        	//shifting - number of key
		    	            for (int i = 0; i < key; i++)
		    	            {
		    	                if (encodedText[count] == 'z')
		    	                    encodedText[count] = 'a';
		    	                else if (encodedText[count] =='Z')
		    	                	encodedText[count] = 'A';
		    	                else
		    	                    encodedText[count]++;
		    	            }
		    	        }
		    	    }
	 return encodedText;

}
//function get from www.cplusplus.com/
//modified from Grigoris Kokozides
string Decode(int key, string text)
{
	int count;
	int size;
    //catch the size of the string that user inputs
	size = (int)text.size();
    string DecodedText = text;
	for (count=0; count < size; count++)
	    {
	        if (DecodedText[count] >= 'A' && DecodedText[count] <= 'Z')
	        {
	        	DecodedText[count] = (char)(((DecodedText[count] - key - 'A' + 26) % 26) + 'A');
	        }
	        else if (DecodedText[count] >= 'a' && DecodedText[count] <= 'z')
	        {
	        	DecodedText[count] = (char)(((DecodedText[count] - key - 'a' + 26) % 26) + 'a');
	        }
	    }
	return DecodedText;

}











