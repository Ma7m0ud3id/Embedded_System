/*
 * Linked_list_task_unit4.c
 *
 *  Created on: Jul 19, 2023
 *      Author: mahmo
 */

#include <stdio.h>
#include "Linked_list_task.h"
int main(){
	char temp_text[40];
			int num=0;
			while(1)
			{
				DPRINTF("\n =====================================================");
				DPRINTF("\n\t Choose One of the Following Options \n");
				DPRINTF("\n 1: Add Student ");
				DPRINTF("\n 2: Delete Student ");
				DPRINTF("\n 3: View All Students ");
				DPRINTF("\n 4: Delete All Students ");
				DPRINTF("\n 5: View Nth Student ");
				DPRINTF("\n 6: Number Of Students ");
				DPRINTF("\n 7: Reverse List Of Students ");
				DPRINTF("\n Enter Option Number: ");

				gets(temp_text);
				DPRINTF("\n =====================================================");

				switch(atoi(temp_text))
				{
				case 1:
					Add_Student();
					break;
				case 2:
					Delete_Student();
					break;
				case 3:
					View_All_Students();
					break;
				case 4:
					Delete_All_Students();
					break;
				case 5:
					View_Nth_Student();
					break;
				case 6:
					num = Num_Of_Students ();
					DPRINTF("\n The Total Number of Students is: %d", num);
					break;
				case 7:
					Reverse_List_of_Students ();
					break;
				default:
					DPRINTF("\n Invalid Option Number, Please Try Again ");
					break;
				}

			}
			return 0;
}
