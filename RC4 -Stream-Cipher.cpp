#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<int> permute(vector<int>, vector<int>);
string encrypt(vector<int>s , vector<int> t, string p);
string decrypt(vector<int>s, vector<int> t, string p);

int main() {

	string plaintext = "cryptology";
	string plaintext2 = "RC4";
	vector<int> S(256);		//Fill with for loop
	vector<int> T(256); 	// Fill with key 

	int key[] = { 1,2,3,6 };
	int key2[] = { 5,7,8,9 };


	// Initilize the S and T vectors
	int tmp = 0;
	for (int i = 0; i < 256;i++) {
		S[i] = i;
		T[i] = key[( i % (sizeof(key)/sizeof(*key)) )];
	}

	S = permute(S, T);

	for (int i = 0; i < 256 ;i++) {
		cout << S[i] << " ";	
		if ((i + 1) % 16 == 0)
			cout << endl;
	}

	cout << endl;
	string p = encrypt(S, T, plaintext);
	cout << "Message: " << plaintext << endl;
	cout << "Encrypted Message: " << " " << p << endl;
	cout << "Decrypted Message:  " << decrypt(S, T, p) << endl << endl;
	
	//Init S and T
	tmp = 0;
	for (int i = 0; i < 256;i++) {
		S[i] = i;
		T[i] = key2[(i % (sizeof(key) / sizeof(*key)))];
	}

	S = permute(S, T);

	for (int i = 0; i < 256;i++) {
		cout << S[i] << " ";
		if ((i + 1) % 16 == 0)
			cout << endl;
	}

	cout << endl;
	p = encrypt(S, T, plaintext2);
	cout << "Message: " << plaintext2 << endl;
	cout << "Encrypted Message: " << p << endl;
	cout << "Decrypted Message: "<<decrypt(S, T, p) << endl << endl;


 	system("pause");
	return 0;
}

string decrypt(vector<int>s, vector<int> t, string p) {
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;


	//temp variables
	int b;
	int c;

	int * plain = new int[p.length()];
	string plain_T;

	for (int r = 0; r < p.length(); r++) {

		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		// swap section
		b = s[i];
		s[i] = s[j];
		s[j] = b;

		tmp = (s[i] + s[j]) % 256;
		k = s[tmp];

		c = ((int)p[r] ^ k);	// cast the p string as and int then xor with k

		plain[r] = c;

		plain_T += (char)plain[r];	// Cast plaintext int array as a char

	}
	return plain_T;
}

string encrypt(vector<int>s, vector<int> t, string p) {

	int i = 0;
	int j = 0;
	int tmp = 0; 
	int k = 0;

	//Temp variables
	int b;	
	int c;

	int * cipher = new int [p.length()];
	string cipher_T;
	cout << "Keys Generated for plaintext: ";

	for (int r = 0; r < p.length(); r++) {

		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		// swap section
		b = s[i];
		s[i] = s[j];
		s[j] = b;

		tmp = (s[i] + s[j]) % 256;
		k = s[tmp];

		cout << k << " ";
		c = ((int)p[r] ^ k);	//Cast p char as an int then xor with k
		
		cipher[r] = c;		

		cipher_T += (char)cipher[r];  //cast int as char then append to string

	}
	cout << endl;
	return cipher_T;
}


vector<int> permute(vector<int> s, vector<int> t) {
	int j = 0;
	int tmp;
	for (int i = 0; i< 256; i++) {
		j = (j + s[i] + t[i]) % 256;
		
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	return s;
}

