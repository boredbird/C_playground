#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#define DATA_FILE "data.dat"

typedef struct log
{
	char DateTime[25];
	char W_D;	/*withdraw or deposit*/
	float Amount;
} log;

typedef struct node_log
{
	log data;
	struct node_log *next;
} node_log, *p_node_log;

typedef struct account
{
	char ID[10];
	char Name[10];
	float Balance;
} account;

typedef struct node_account
{
	account data;
	struct node_log *nlog;
	struct node_account *next;
} node_account, *p_node_account;

p_node_account headAccount;

void PrintAccountTitle();
void PrintAccount(account);
void PrintLogTitle();
void PrintLog(log);

void Read();
void Write();
void List(int);

void Create();
void Distroy();
void Deposit();
void Withdraw();

void FreeLogs(p_node_log);

p_node_account FindAAccount(char *);

void main()
{
	char choice = '0';
	headAccount = NULL;

	do
	{
		system("cls");

		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n\n");
		printf("1. Read file;\n");
		printf("2. Create account;\n");
		printf("3. Distroy account;\n");
		printf("4. Deposit;\n");
		printf("5. Withdraw;\n");
		printf("6. List all account;\n");
		printf("7. Find account;\n");
		printf("8. Find log;\n");
		printf("9. Write file;\n");
		printf("0. Exit.\n");
		printf("------------------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%c", &choice);

		switch(choice)
	  	{
	    	case '1':
	    		Read();		break;
	     	case '2':
	    		Create();  	break;
	     	case '3':
	    		Distroy(); 	break;
	     	case '4':
	    		Deposit(); 	break;
	     	case '5':
	    		Withdraw();	break;
	     	case '6':
	    		List(0);		break;
	     	case '7':
	    		List(1); 		break;
	     	case '8':
	    		List(2); 		break;
	     	case '9':
	    		Write(); 		break;
			case '0':
				break;
		    default:
	    		printf("Illegal choice!");
		}
	}while(choice != '0');
}

void PrintAccountTitle()
{
	printf("--------------------------------------------\n");
	printf("      ID      |     Name     |   Balance    \n");
}

void PrintAccount(account p)
{
	printf("  %10s  |  %10s  |  %f\n", p.ID, p.Name, p.Balance);
}

void PrintLogTitle()
{
	printf("--------------------------------------------------\n");
	printf("         DateTime         | W or D |    Amount    \n");
}

void PrintLog(log p)
{
	printf(" %24s |   %c    |  %f\n", p.DateTime, p.W_D, p.Amount);
}

void Read()
{
	FILE *fp;
	p_node_account pNodeAccount;
	p_node_log pNodeLog;
	int size, iLogs;

	fp = fopen(DATA_FILE, "rb");
	fseek(fp, 0, 2);	/*get the size of the file*/
	size = ftell(fp);
	rewind(fp);

	while(size != 0)
	{
		size -= sizeof(struct account);
		pNodeAccount = (p_node_account)malloc(sizeof(node_account));
		if(fread(&pNodeAccount->data, sizeof(struct account), 1, fp) != 1)
			exit(0);
		pNodeAccount->next = headAccount;
		headAccount = pNodeAccount;

		size -= sizeof(int);
		if(fread(&iLogs, sizeof(int), 1, fp) != 1)
			exit(0);
		while(iLogs != 0)
		{
			size -= sizeof(struct log);
			pNodeLog = (p_node_log)malloc(sizeof(node_log));
			if(fread(&pNodeLog->data, sizeof(struct log), 1, fp) != 1)
				exit(0);
			pNodeLog->next = pNodeAccount->nlog;
			pNodeAccount->nlog = pNodeLog;
			iLogs--;
		}
	}
	fclose(fp);

	printf("Read files complete!\n");
	getch();
}

void Write()
{
	FILE *fp;
	p_node_log pNodeLog;
	p_node_account pNodeAccount;
	int iLogs;

	if((fp = fopen(DATA_FILE, "wb+")) == NULL)
	{
		printf("Cann't open file!\n");
		return;
	}

	pNodeAccount = headAccount;
	while(pNodeAccount != NULL)
	{
		if(fwrite(&pNodeAccount->data, sizeof(struct account), 1, fp) != 1)
			printf("File write error!\n");

		iLogs = 0;
		pNodeLog = pNodeAccount->nlog;
		while(pNodeLog != NULL)
		{
			iLogs++;
			pNodeLog = pNodeLog->next;
		}
		if(fwrite(&iLogs, sizeof(int), 1, fp) != 1)
			printf("File write error!\n");

		pNodeLog = pNodeAccount->nlog;
		while(pNodeLog != NULL)
		{
			if(fwrite(&pNodeLog->data, sizeof(struct log), 1, fp) != 1)
				printf("File write error!\n");
			pNodeLog = pNodeLog->next;
		}

		pNodeAccount = pNodeAccount->next;
	}
	fclose(fp);

	printf("Write files complete!\n");
	getch();
}

void List(int type)
{
	p_node_account pNodeAccount;
	p_node_log pNodeLog;
	char sID[10];

	pNodeAccount = headAccount;

	if(type == 0)
	{
		PrintAccountTitle();
		while(pNodeAccount != NULL)
		{
			PrintAccount(pNodeAccount->data);
			pNodeAccount = pNodeAccount->next;
		}
		getch();
		return;
	}

	printf("\nPlease input the account id which you want to list");
	printf("\nAccount ID = ");
	scanf("%s", sID);

	while(pNodeAccount != NULL)
	{
		if(strcmp(pNodeAccount->data.ID, sID) == 0)
		{
			PrintAccountTitle();
			PrintAccount(pNodeAccount->data);

			if(type == 2)
			{
				pNodeLog = pNodeAccount->nlog;

				printf("\n\nAll logs of the account:\n");
				PrintLogTitle();
				while(pNodeLog != NULL)
				{
					PrintLog(pNodeLog->data);
					pNodeLog = pNodeLog->next;
				}
			}
			getch();
			return;
		}
		pNodeAccount = pNodeAccount->next;
	}

	printf("\nNo record is matched!");
	getch();
}

void Create()
{
	p_node_account pNodeAccount;

	pNodeAccount = (p_node_account)malloc(sizeof(node_account));

	printf("\n Account ID = ");
	scanf("%s", pNodeAccount->data.ID);
	printf("\n Name = ");
	scanf("%s", pNodeAccount->data.Name);
	pNodeAccount->data.Balance = 0;
	pNodeAccount->nlog = NULL;
	pNodeAccount->next = NULL;

	if(headAccount == NULL)
		headAccount = pNodeAccount;
	else
	{
		pNodeAccount->next = headAccount;
		headAccount = pNodeAccount;
	}

	PrintAccountTitle();
	PrintAccount(pNodeAccount->data);
	getch();
}

void FreeLogs(p_node_log pNodeLog)
{
	p_node_log tmp;
	while(pNodeLog != NULL)
	{
		tmp = pNodeLog;
		pNodeLog = pNodeLog->next;
		free(tmp);
	}
}

void Distroy()
{
	p_node_account pNodeAccount, p1;
	char sID[10];

	p1 = headAccount;

	printf("\nPlease input the account id which you want to delete");
	printf("\nAccount ID = ");
	scanf("%s", sID);

	if(strcmp(p1->data.ID, sID) == 0)
	{
		if(p1->data.Balance != 0)
		{
			printf("\nThis account is not empty, you must withdraw first!");
		}
		else
		{
			headAccount = p1->next;
			FreeLogs(p1->nlog);
			free(p1);

			printf("\nThis account has been deteled!");
		}
		getch();
		return;
	}

	pNodeAccount = p1->next;

	while(pNodeAccount != NULL)
	{
		if(strcmp(pNodeAccount->data.ID, sID) == 0)
		{
			if(pNodeAccount->data.Balance != 0)
			{
				printf("\nThis account is not empty, you must withdraw first!");
			}
			else
			{
				p1->next = pNodeAccount->next;
				FreeLogs(pNodeAccount->nlog);
				free(pNodeAccount);

				printf("\nThis account has been deteled!");
			}
			getch();
			return;
		}

		p1 = pNodeAccount;
		pNodeAccount = pNodeAccount->next;
	}

	printf("\nNo account is matched!");
	getch();
}

void Withdraw()
{
	char accountID[10];
	float amount;
	p_node_account pNodeAccount;
	p_node_log pNodeLog;
	time_t t;

	printf("\nPlease input the account id which you want to withdraw");
	printf("\nAccountID = ");
	scanf("%s", accountID);

	pNodeAccount = FindAAccount(accountID);
	if(pNodeAccount == NULL)
	{
		printf("\nThis account is not exist!");
		getch();
		return;
	}

	printf("\nPlease input the withdraw amount");
	printf("\nWithdraw amount = ");
	scanf("%f", &amount);

	if(pNodeAccount->data.Balance < amount)
	{
		printf("\nYour withdraw amount more than you have!");
		getch();
		return;
	}

	pNodeAccount->data.Balance -= amount;
	t=time(NULL);

	pNodeLog = (p_node_log)malloc(sizeof(node_log));
	strcpy(pNodeLog->data.DateTime, ctime(&t));
	pNodeLog->data.DateTime[24] = '\0';
	pNodeLog->data.W_D = 'W';
	pNodeLog->data.Amount = amount;
	pNodeLog->next = pNodeAccount->nlog;
	pNodeAccount->nlog = pNodeLog;


	printf("\nWithdraw success!");

	getch();
}

void Deposit()
{
	char accountID[10];
	float amount;
	p_node_account pNodeAccount;
	p_node_log pNodeLog;
	time_t t;

	printf("\nPlease input the account id which you want to deposit");
	printf("\nAccountID = ");
	scanf("%s", accountID);

	pNodeAccount = FindAAccount(accountID);
	if(pNodeAccount == NULL)
	{
		printf("\nThis account is not exist!");
		getch();
		return;
	}

	printf("\nPlease input the deposit amount");
	printf("\nDeposit amount = ");
	scanf("%f", &amount);

	pNodeAccount->data.Balance += amount;
	t=time(NULL);

	pNodeLog = (p_node_log)malloc(sizeof(node_log));
	strcpy(pNodeLog->data.DateTime, ctime(&t));
	pNodeLog->data.DateTime[24] = '\0';
	pNodeLog->data.W_D = 'D';
	pNodeLog->data.Amount = amount;
	pNodeLog->next = pNodeAccount->nlog;
	pNodeAccount->nlog = pNodeLog;

	printf("\nDeposit success!");

	getch();
}

p_node_account FindAAccount(char *accountID)
{
	p_node_account pNodeAccount, pReturn;

	pReturn = NULL;
	pNodeAccount = headAccount;
	while(pNodeAccount != NULL)
	{
		if(strcmp(pNodeAccount->data.ID, accountID) == 0)
		{
			pReturn = pNodeAccount;
			break;
		}
		pNodeAccount = pNodeAccount->next;
	}
	return pReturn;
}
