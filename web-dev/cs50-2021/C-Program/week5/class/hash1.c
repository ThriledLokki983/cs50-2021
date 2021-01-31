#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TABLE 5 // size of table
#define MAX_KEYS 48 // include null
#define MAX_DATA 12 // num of data for hash table
#define DELETE_COUNT 6 // num of data for deletion
#define FIND_COUNT 8 // num of data for finding

// Node structure
typedef struct head
{
 char key[MAX_KEYS];
 int value;
 struct head *next;
}head;

 // Hash table
head *table[MAX_TABLE];
char keys[MAX_DATA][MAX_KEYS];
int values[MAX_DATA];

void hash_init()
{
   // Hash table initialization
   for (int i = 0; i < MAX_TABLE; i++)
   {
    head *cur = table[i];
    head *tmp;
      while (cur != NULL)
      {
       tmp = cur;
       cur = cur -> next;
       free(tmp);
      }
    table[i] = NULL;
   }


  // Srand and seed for a random function
  srand(time(NULL));

  // Initialize values
  for (int i = 0; i < MAX_DATA; i++)
  {
   values[i] = rand() % 100 + 1;
  }


  // Initialize keys 
  for (int i = 0; i < MAX_DATA; i++)
  {
   for (int j = 0; j < MAX_KEYS - 1; j++)
   {
    keys[i][j] = rand() % 26 + 97; //ASCII 97 ~ 122
   }
   keys[i][MAX_KEYS - 1] = '\0';
  }

}

void str_cpy(char *dest, const char *src)
{
 while (*src != '\0')
 {
  *dest = *src;
  dest ++; src++;
 }
 *dest = '\0';
}

int str_cmp(const char *str1, const char *str2)
{
 while (*str1 != '\0' && (*str1 == *str2))
 {
  str1++;
  str2++;
 }
 return *str1 - *str2;
}

int hash(const char *str)
{
 int hash = 401;
 int c;
 while (*str != '\0')
 {
  hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
  str++;
 }
 return hash % MAX_TABLE;
}

void add(const char *key, int value)
{
 head *new_head = (head *)malloc(sizeof(head));
 str_cpy(new_head -> key, key);
 new_head -> value = value;
 new_head ->next = NULL;

 int index = hash(key);

 // Insert if fisrt is NULL
 if (table[index] == NULL)
 {
  table[index] = new_head;
 }

 // Traverse list one by one
 // Change duplicated value if not then add it to the front

else
  {
   head *cur = table[index];
   while (cur != NULL)
   {
    // if key is duplicated, then replace its value
    if(str_cmp(cur->key, key) == 0)
    {
     cur -> value = value;
     return;
    }
    cur = cur -> next;
   }
   // add to front if it is not duplicated
   new_head -> next = table[index];
   table[index] = new_head;
  }
}

bool find(const char *key, int *val)
{
 int index = hash(key);
 head *cur = table[index];

 // Find the key by traversing list one by one
 while (cur != NULL)
 {
  if(str_cmp(cur ->key, key) == 0)
  {
   *val = cur -> value;
   return true;
  }
  cur = cur ->next;
 }
 return false;
}

bool destroy (const char *key){
 int index = hash(key);

 // Check first of list
 if (table[index] == NULL)
 {
  return false;
 }

 // Check first element
 if (str_cmp(table[index] ->key, key) == 0)
 {
  head *first = table[index];
  table[index] = table[index] -> next;
  free(first);
  return true;
 }

 // Others

 else
 {
  head *cur = table[index]->next;
  head *prev = table[index];

  while (cur != NULL && str_cmp(cur ->key, key) != 0)
  {
   prev = cur;
   cur = cur -> next;
  }
  if (cur == NULL)
  {
   return false;
  }
  else
  {
   prev ->next = cur->next;
   free(cur);
   return true;
  }
 } 
}

void print_hash()
{
 for (int i = 0; i < MAX_TABLE; i++)
 {
  if (table[i] != NULL)
  {
   printf("index: %d\n", i);
   head *cur = table[i];

   while (cur != NULL)
   {
    printf("{%s, %d},", cur->key, cur->value);
    cur = cur-> next;
   }
   printf("\n");
  }
 }
}

int main()
{
 char tmp_key[MAX_KEYS];
 hash_init();

 // Add
 printf("Add to hash table\n");
 for (int i = 0; i < MAX_TABLE; i++)
 {
  add(keys[i],values[i]);
 }

 print_hash();
 printf("\n");

 // Delete
 printf("Deleted Keys: ");
 for (int i = 0; i < DELETE_COUNT; i++)
 {
  str_cpy(tmp_key, keys[rand() % MAX_DATA]);
  printf("%s", tmp_key);
  destroy(tmp_key);
 }
 printf("\n");

 print_hash();

 printf("\n");

 // Search 

 int val;
 printf("Found: ");
 for (int i = 0; i < FIND_COUNT; i++)
 {
  str_cpy(tmp_key, keys[rand() % MAX_DATA]);
  if (find(tmp_key, & val))
  {
   printf("{%s, %d}", tmp_key, val);
  }
 }
 printf("\n");
 return 0;

 
 
}


 



// HASH FUNCTION

