#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return true;
	}
	return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	for(int i =0; i < num_chars; i++){
		int nv_count = 0;
		if(!is_vowel(in_buf[i])){
			out_buf[i] = in_buf[i];
			nv_count++;
		}	
	}
free(in_buf);
return nv_count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	in_file = fopen("inputFile", "r");
	out_file = fopen("outputFile", "w");
	char* input_buf[BUF_SIZE];
	char* output_buf[BUF_SIZE};
	//Empty space is length of inputFile
	fread(input_buf, sizeOf(char*), BUF_SIZE ,in_file);
	fread(output_buf, sizeOf(char*), BUF_SIZE, out_file);
	copy_non_vowels(num, input_buf, output_buf);
	fclose(in_file);
	fclose(out_file);

}

int main(int argc, char *argv[]) {
	FILE *inputFile;
	FILE *outputFile;

	disemvowel(inputFile, outputFile);

	return 0;
}
