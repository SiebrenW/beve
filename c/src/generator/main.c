#include <stdint.h>
#include <stdio.h>

enum TokenType {
  TOKEN_TYPE_Start,
  TOKEN_TYPE_End,
  TOKEN_TYPE_Error,
  TOKEN_TYPE_Integer,
  TOKEN_TYPE_Float,
  TOKEN_TYPE_String,
  TOKEN_TYPE_Operator,
  TOKEN_TYPE_Whitespace,
  TOKEN_TYPE_Newline,
};

struct TokenEntry {
  const char *value;
  enum TokenType type;
};

struct TokenEntry TOKENS[] = {
    // {"+", TOKEN_TYPE_OPERATOR},
    {"\n", TOKEN_TYPE_Newline},
    {"\"", TOKEN_TYPE_String},
};

struct Allocator {
  void *(*alloc)(size_t size, struct Allocator *allocator);
  void (*free)(void *ptr, struct Allocator *allocator);
};

struct config {};

struct Token {
  uint32_t position : 24;
  enum TokenType type : 8;
};

static const struct Token INVALID_TOKEN = {0, TOKEN_TYPE_Error};

struct Source {
  const char *data;
  ssize_t length;
};

struct TokenNode {
  struct Token token;
  struct TokenNode *next;
};

typedef struct ErrorList ErrorList;

struct Tokenizer {
  struct Source source;
  struct TokenNode *tokens;
  struct TokenNode *current;
  struct TokenNode *previous;
  struct ErrorList *errors;
};

void init_Source(struct Source*source) {
  source->data = NULL;
  source->length = 0;
}

void init_Tokenizer(struct Tokenizer *tokenizer) {
  init_Source(&tokenizer->source);
  tokenizer->tokens = NULL;
  tokenizer->current = NULL;
  tokenizer->previous = NULL;
  tokenizer->errors = NULL;
}

enum ERROR_CODE {
  ERROR_CODE_OK = 0,
  ERROR_CODE_INVALID_TOKEN,
  ERROR_CODE_INVALID_SOURCE,
  ERROR_CODE_INVALID_ALLOCATOR,
  ERROR_CODE_NO_SELECTED_TOKEN,
  ERROR_CODE_NO_NEXT_TOKEN,
};

int tokenizer_next(struct Tokenizer* self) {
  if (self->current == NULL) {
    if (self->tokens == NULL) {
      return ERROR_CODE_NO_SELECTED_TOKEN;
    }
    self->current = self->tokens;
  }
  self->previous = self->current;

  return 0;
}

struct TokenNode *appendToken(struct TokenNode *head,
                              struct Allocator *allocator) {
  struct TokenNode *node = head;
  while (head->next != NULL) {
    node = node->next;
  }
  struct TokenNode *newNode =
      (struct TokenNode *)allocator->alloc(sizeof(struct TokenNode), allocator);
  newNode->token.type = 0;
  newNode->next = NULL;
  node->next = newNode;
  return newNode;
}

struct TokenCollection {};

int tokenize_string(const char *input, struct config *config) {
  printf("Tokenizing string: %s\n", input);
  return 0;
}

int main(int argc, char *const *const argv) {
  printf("Hello, World!\n");
  return 0;
}