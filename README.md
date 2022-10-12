# GNL
Get Next Line is the second C project in the École 42 curriculum. It can read files and get a single line on each call of the ``get_next_line()``  function. The program reads from multiple files without losing track of what was already read, so it each call starts from the next line.

# Use
To use and test it, you just have to clone the repository and then compile get_next_line.c together with get_next_line_utils.c and main.c,
and then execute the binary giving as many files as you want as arguments, like so: 
### ./a.out banner.txt

# Example
Here is a fun, althought not practical, example of the GNL being used. In this case it is simply passing line by line from the banner.txt file
to the int main function where the program prints them, line by line, on the terminal standard output:

![WhatsApp Image 2022-10-11 at 19 40 08](https://user-images.githubusercontent.com/92558763/195225628-7b664682-20e8-4a04-811c-d55c62655a4e.jpeg)

Those text files with ascii characters forming cool images are called ascii art by the way

![WhatsApp Image 2022-10-11 at 19 43 05](https://user-images.githubusercontent.com/92558763/195225739-da990003-290a-4588-b304-23ed2a11b11b.jpeg)

They can be automatically generated on this website: https://www.ascii-art-generator.org/

## There are practical uses for GNL and I'll be updating this readme with more information.
