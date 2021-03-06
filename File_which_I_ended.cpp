/*
*
*Created by UnitedTimur
* 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

FILE *tmp = fopen("tmp.txt", "wt"), *out = fopen("out.txt", "wt");

void error() {

	system("cls");
	cout << "Error. Try again ;(" << endl;
	system("pause");
	exit(-1);

}

void rewrite_to_out() {

	fclose(tmp);

	tmp = fopen("tmp.txt", "rt");

	char ch = {};

	fscanf(tmp, "%c", &ch);

	while (!feof(tmp)) {

		fprintf(out, "%c", ch);
		fscanf(tmp, "%c", &ch);

	}

	fclose(tmp);

	tmp = fopen("tmp.txt", "wt");

}

void main(void) {

	FILE *in;

	in = fopen("in.txt", "rt");

	if (in == NULL) error();

	char ch = {};
	char word[100] = {};
	char tmp_word[100] = {};

	unsigned int size = 0;
	unsigned int count = 0;
	unsigned int tmp_size = 0;

	fscanf(in, "%c", &ch);

	if (in == NULL) error();

	while (!feof(in)) {

		if (isdigit(ch) || isalpha(ch)) {

			word[size++] = ch;
	
		}
		else {

			if (size < 3 || size > 5) {

				for (int i = 0; i < size; i++)
					fprintf(tmp, "%c", word[i]);

			}
			else {

				rewrite_to_out();

				if (tmp_size == 0) {

					tmp_size = size;

					for (int i = 0; i < size; i++)
						tmp_word[i] = word[i];
				}
				else 
					tmp_size = 0;
			}
			
			if (ch == '\n') {

				if (tmp_size) {

					for (int i = 0; i < tmp_size; i++)
						fprintf(out, "%c", tmp_word[i]);

				}

				tmp_size = 0;

			}
			
			fprintf(tmp, "%c", ch);

			size = 0;
		}

		fscanf(in, "%c", &ch);
	}

	if (tmp_size) {

		for (int i = 0; i < tmp_size; i++) {

			fprintf(out, "%c", tmp_word[i]);

		}

	}

	rewrite_to_out();

	if (size) {
			
		for (int i = 0; i < size; i++) {

			fprintf(out, "%c", word[i]);

		}

	}

	_fcloseall();

}
