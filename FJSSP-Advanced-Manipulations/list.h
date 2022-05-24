#ifndef LIST
#define LIST

/// <summary>
/// Defines a generic list
/// </summary>
typedef struct List {
	void* data;
	struct List* next;
}List;

#endif