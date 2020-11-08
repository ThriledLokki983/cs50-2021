# Build mylines as shown above

mylines = []                                # Declare an empty list.
with open ('dna/sequences/19.txt', 'r') as myfile:    # Open lorem.txt for reading text.
    for myline in myfile:                   # For each line in the file,
        mylines.append(myline.rstrip('\n')) # strip newline and add to list.

# Locate and print all occurences of letter "e"

index = 0                     # current index
prev = 0                      # previous index
str = mylines[0]              # string to be searched (first element of mylines)
substr = "AGATC"                  # substring to search for
while index < len(str):       # While index has not exceeded string length,
  index = str.find(substr, index)  # set index to first occurrence of "e"
  if index == -1:             # If nothing was found,
    break                     # exit the while loop.
  ##print(" " * (index - prev) + "AGATC", end='')  # print location of this "e"
  prev = index + len(substr)  # set previous to index + 1
  index += len(substr)        # increment the index by the length of substr.
                              # (Repeat while loop until index >= len(str))
##print('\n' + str);
print(len(substr))