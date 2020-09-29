#include "file_disemvowel.h"

#define BUF_SIZE 1024

bool is_vowel(char c) {
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return true;

	}
	return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	// number of non-vowels
	int nv_count = 0;
	for(int i =0; i < num_chars; i++){
		// counter for out_buf
		if(!is_vowel(in_buf[i])){
			out_buf[nv_count] = in_buf[i];
			nv_count++;
		}	
	}
free(in_buf);
return nv_count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* input_buf = (char*)calloc(BUF_SIZE, 1);
	char* output_buf = (char*)calloc(BUF_SIZE, 1);
	//Empty space is length of inputFile
	fread(input_buf, 1, BUF_SIZE ,inputFile);
	copy_non_vowels(BUF_SIZE, input_buf, output_buf);
	fwrite(output_buf, 1, BUF_SIZE, outputFile);

}

int main(int argc, char *argv[]) {
	FILE *inputFile = stdin;
	FILE *outputFile = stdout;

	disemvowel(inputFile, outputFile);
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
