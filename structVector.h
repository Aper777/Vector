#include <stdlib.h>

typedef struct {
	size_t size;
	size_t capacity;
	int *arr;
}Vector;
void ctor(Vector* ptr){
	ptr->size = 0;
	ptr->capacity = 10;
	ptr->arr =(int*)malloc(ptr->capacity * sizeof(int));
	if(ptr->arr == NULL){
		perror("memory alocation failed\n");
		exit(EXIT_FAILURE);
	}
}
void push_back(Vector* ptr,int val){
	if(ptr->size == ptr->capacity){
		 ptr->capacity = (ptr->size) + 1;
		ptr->arr = realloc(ptr->arr,ptr->capacity * sizeof(int));
	}
	ptr->arr[ptr->size] = val;
	ptr->size++;
}
void pop_back(Vector* ptr){
	ptr->capacity = (ptr->size) - 1;
	ptr->arr = realloc(ptr->arr,ptr->capacity * sizeof(int));
	ptr->size--;
}
size_t size(Vector* ptr){
	return ptr->size;
}
size_t capacity(Vector *ptr){

	return ptr->capacity;
}
void in_sert(Vector *ptr,size_t index,int val){
	if(ptr->size == ptr->capacity){
		ptr->capacity *= 1,2;
		ptr->arr =realloc(ptr->arr,ptr->capacity * sizeof(int));
	}
	++ptr->size;
	for(int i = ptr->size; i > index;i--){
		ptr->arr[i]=ptr->arr[i-1];	
	}
	ptr->arr[index] = val;
}
void erase(Vector *ptr,size_t index){
	for(int i = index;i < ptr->size - 1;i++){
		ptr->arr[i] = ptr->arr[i + 1];
	}
	--ptr->size;
}

void clear(Vector *ptr){
	ptr->size = 0;
}

void print(Vector *ptr){
	for(int i = 0;i < ptr->size;i++){
		printf("%d",ptr->arr[i]);
	}
	putchar(10);
}
void insert_range(Vector *ptr,size_t start,size_t end,int val){
	size_t ch_size = ptr->size;
	ptr->size += (end - start + 1); 
	if(ptr->capacity < ptr->size){
		ptr->capacity *= 2;
		ptr->arr = realloc(ptr->arr,ptr->capacity *sizeof(int));
	}
	int tmp = end;
	for(int i = ptr->size;i > ch_size;i-- ){
		ptr->arr[i] = ptr->arr[end];
		ptr->arr[end] = val;
		--end;
	}
}
void dtor(Vector *ptr){
	free(ptr->arr);
}




