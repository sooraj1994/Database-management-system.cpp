//# Database-management-system.cpp
//This is a cpp program to maintain muliple tables
//In visual studio
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

#define DASHES 10

using namespace std;

void insert_row(void);
void modify_row(void);
void delet_row(void);
void create_table();
void display_table();
void delete_table();
int row = 0, col = 0;
int dashes = 0;

class entry
{
public:
	char entry_name[15];
	char table_name[15];
	entry * pointer_right = 0;
	entry * pointer_down = 0;
};
entry * first;

class table_list
{
public:
	char table_name[15];
	table_list *pointer;
	entry table_pointer;
	int rows = 0;
	int cols = 0;
};
table_list *table_first = new table_list;

void main()
{
	int choice, i, j;
	int c, table_count = 0, n;
	table_list *tptr = table_first;
	while (1)
	{
		printf("\n1.Manage table\n");
		printf("\n2.Create table\n");
		printf("\n3.Delete table\n");
		printf("\n4.Display table list\n");
		printf("\n0.Exit\n");
		printf("\nEnter your choice\n\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:system("cls");
			if (table_count == 0)
			{
				printf("\nNo table to Manage\n");
				getch();
				break;
			}
			tptr = table_first;
			for (n = 0; n < table_count; n++)
			{
				tptr = tptr->pointer;
				printf("\n%d.%s\n", n, tptr->table_name);

			}
			printf("\nEnter the table index to manage\n");
			tptr = table_first;
			scanf("%d", &choice);
			system("cls");
			tptr = table_first;
			for (n = 0; n < choice; n++)
			{
				tptr = tptr->pointer;
			}
			first = &tptr->table_pointer;
			row = tptr->rows;
			col = tptr->cols;
			while (choice)
			{
				system("cls");
				printf("\n\n%s\n\n-------------------\n", tptr->table_name);
				printf("\n1.Insert row into table\n");
				printf("\n2.Modify row in table\n");
				printf("\n3.Delete row from table\n");
				printf("\n4.Change table structure\n");
				printf("\n5.Display contents of table\n");
				printf("\n0.Exit\n");
				printf("\nEnter a choice:\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 0:break;
				case 1:insert_row();
					break;
				case 2:modify_row();
					break;
				case 3:delet_row();
					break;
				case 4:create_table();
					break;
				case 5:display_table();
					getch();
					break;
				default:printf("\nEnter proper choice\n");
					_sleep(1000);
				}
			}
			system("cls");
			tptr->rows = row;
			tptr->cols = col;
			break;
		case 2:
			system("cls");
			tptr = table_first;
			for (n = 0; n < table_count; n++)
				tptr = tptr->pointer;
			tptr->pointer = new table_list;
			tptr = tptr->pointer;
			table_count++;
			printf("\nEnter table name\n");
			scanf("%s", tptr->table_name);
			system("cls");
			first = &tptr->table_pointer;
			row = tptr->rows;
			col = tptr->cols;
			while (choice)
			{
				system("cls");
				printf("\n\n%s\n\n-------------------\n", tptr->table_name);
				printf("\n1.Insert row into table\n");
				printf("\n2.Modify row in table\n");
				printf("\n3.Delete row from table\n");
				printf("\n4.Change table structure\n");
				printf("\n5.Display contents of table\n");
				printf("\n0.Exit\n");
				printf("\nEnter a choice:\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 0:break;
				case 1:insert_row();
					break;
				case 2:modify_row();
					break;
				case 3:delet_row();
					break;
				case 4:create_table();
					break;
				case 5:
					printf("\n\n%s\n\n", tptr->table_name);
					display_table();
					getch();
					break;
				default:printf("\nEnter proper choice\n");
					_sleep(1000);
					break;
				}
			}
			tptr->rows = row;
			tptr->cols = col;
			system("cls");
			break;
		case 0:exit(0);
		case 4:system("cls");
			if (table_count == 0)
			{
				printf("\nNo tables to display\n");
				getch();
				break;
			}
			printf("\nCreated tables are\n");
			tptr = table_first;
			for (n = 1; n <= table_count; n++)
			{
				tptr = tptr->pointer;
				printf("\n%d.%s\n", n, tptr->table_name);
			}
			getch();
			system("cls");
			break;
		case 3:
			if (table_count == 0)
			{
				system("cls");
				printf("\nNo table to delete\n");
				getch();
				break;
			}
			system("cls");
			tptr = table_first;
			for (n = 1; n <= table_count; n++)
			{
				tptr = tptr->pointer;
				printf("\n%d.%s\n", n, tptr->table_name);
			}
			printf("\nEnter the table index to be deleted\n");
			scanf("%d", &choice);
			tptr = table_first;
			table_list *temp;
			for (n = 0; n < (choice - 1); n++)
				tptr = tptr->pointer;
			if (choice == 1)
			{
				temp = table_first;
				table_first = table_first->pointer;
			}
			else
			{
				temp = tptr->pointer;
				tptr->pointer = (tptr->pointer)->pointer;
			}
			first = &(temp->table_pointer);
			col = temp->cols;
			row = temp->rows;
			table_count--;
			break;
		default:printf("\nEnter proper choice\n");
			getch();
			break;
		}
		system("cls");
		tptr->rows = row;
		tptr->cols = col;
	}
}

void create_table()
{
	entry *ptr;
	int more = 1;
	ptr = first;
	col = 0;
	row = 0;
	first->pointer_down = '\0';
	system("cls");
	for (ptr = first; more == 1; ptr = ptr->pointer_right)
	{
		system("cls");
		printf("\nEnter the entry\n");
		scanf("%s", ptr->entry_name);
		col++;
		printf("\nPress 1 if there are more entries else press 0\n");
		scanf("%d", &more);
		if (more != 1)
		{
			return;
		}
		ptr->pointer_right = new entry;
	}
	system("cls");
	printf("\nEntries are\n\n");
	int count = 0;
	for (ptr = first; count < col; ptr = ptr->pointer_right)
	{
		printf("%s\t", ptr->entry_name);
		count++;
	}
}

void display_table()
{
	int i, j;
	entry *ptr1, *ptr2;
	system("cls");
	if (col == 0 || row == 0)
	{
		printf("\nNo data in table to display\n");
		return;
	}
	printf("\n\nEntries are\n\n");
	ptr1 = first;

	for (i = 0; i <= row; i++, ptr1 = ptr1->pointer_down)
	{
		ptr2 = ptr1;
		printf("\t\t");
		if (i != 0)
		{
			printf("%d.\t", i);
		}

		for (j = 0; j < col; j++, ptr2 = ptr2->pointer_right)
		{
			printf("%s\t", ptr2->entry_name);
		}
		if (i == 0)
		{
			printf("\n\t");
			for (j = 0; j < (DASHES*col); j++)
				printf("-");
		}

		printf("\n\n");
	}

}

void insert_row()
{
	int i, j;
	entry *ptr1, *ptr2;
	ptr1 = first;
	system("cls");
	if (col == 0)
	{
		printf("\nNo attributes to insert\n");
		getch();
		return;
	}
	for (i = 0; i < row; i++)
		ptr1 = ptr1->pointer_down;
	ptr2 = new entry;
	ptr1->pointer_down = ptr2;
	system("cls");
	ptr1 = first;
	for (i = 0; i < col; i++)
	{
		printf("\nEnter %s\n", ptr1->entry_name);
		scanf("%s", &(ptr2->entry_name));
		ptr1 = ptr1->pointer_right;
		ptr2->pointer_right = new entry;
		ptr2 = ptr2->pointer_right;
	}
	row++;

}

void modify_row()
{
	int n, i;
	entry * ptr1, *ptr2;
	system("cls");
	if (row == 0)
	{
		printf("\nNo data to modify\n");
		getch();
		return;
	}
	display_table();
	printf("Enter the index of row to be modified\n");
	scanf("%d", &n);
	ptr1 = first;
	ptr2 = first;
	if (n > 0 && n>row)
	{
		system("cls");
		printf("\nRow is not available\n");
		getch();
		return;
	}
	for (i = 0; i < n; i++)
		ptr2 = ptr2->pointer_down;
	for (i = 0; i < col; i++)
	{
		printf("\nEnter the entry %s\n", ptr1->entry_name);
		scanf("%s", &(ptr2->entry_name));
		ptr1 = ptr1->pointer_right;
		ptr2 = ptr2->pointer_right;
	}

}

void delet_row()
{
	int n, i,j;
	entry *ptr1, *ptr2;
	entry *temp1,*temp2;
	system("cls");

	if (col == 0 || row == 0)
	{
		printf("\nNo data to delete\n");
		getch();
		return;
	}

	system("cls");
	if (col == 0 || row == 0)
	printf("\n\nEntries are\n\n");
	ptr1 = first;
	for (i = 0; i <= row; i++, ptr1 = ptr1->pointer_down)
	{
		ptr2 = ptr1;
		printf("\t");
		for (j = 0; j < col; j++, ptr2 = ptr2->pointer_right)
		{
			printf("%s\t", ptr2->entry_name);
		}
		if (i == 0)
		{
			printf("\n");
			for (j = 0; j < DASHES; j++)
				printf("-\t ");
		}

		printf("\n\n");
	}

	printf("\nEnter the index of row to be deleted\n");
	scanf("%d", &n);
	if (n > row && n<1)
	{
		system("cls");
		printf("\nInvalid row\n");
		getch();
		return;
	}
	ptr1 = first;
	for (i = 0; i < n - 1; i++)
		ptr1 = ptr1->pointer_down;
	ptr2 = ptr1->pointer_down;
	temp1 = ptr2;
	ptr1->pointer_down = ptr2->pointer_down;
	for (i = 0; i < col; i++)
	{
		temp2 = temp1->pointer_right;
		delete temp1;
		temp1 = temp2;
	}
	for (i = 0; i < col; i++)
	{
		ptr2 = ptr1->pointer_right;
	}
	row--;
	return;
}
