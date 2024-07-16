The `wc` (word count) command in Linux is used to count the number of lines, words, and bytes in files. Here are some common options used with `wc`:

- `wc` without options: displays the number of lines, words, and bytes in the file(s).
- `wc -l`: displays the number of lines.
- `wc -w`: displays the number of words.
- `wc -c`: displays the number of bytes.
- `wc -m`: displays the number of characters.
- `wc -L`: displays the length of the longest line.

For example, `wc filename` will show the counts for the specified file, and `wc -l filename` will show just the line count.
  
   My word_cont command
   
We have 5 files(help, version, wc.c, wc.h and word_count.c)

The main code is word_count.c
To compile this code use this command:

$gcc word_count.c wc.c -o word_count
To execute use:

'./word_count <option> <file>'


