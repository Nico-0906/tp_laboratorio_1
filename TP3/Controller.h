

/**
 * @brief
 * @param path
 * @param pArrayEmployee
 * @return
 */
int controller_loadFromText(char* path , LinkedList* pArrayEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayEmployee);
int controller_addEmployee(LinkedList* pArrayEmployee);
int controller_editEmployee(LinkedList* pArrayEmployee);
int controller_removeEmployee(LinkedList* pArrayEmployee);
int controller_ListEmployee(LinkedList* pArrayEmployee);
int controller_sortEmployee(LinkedList* pArrayEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayEmployee);
int menuOpcionesSort();
