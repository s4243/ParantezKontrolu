#include<stdio.h>
#include<stdlib.h>//malloc için kullanýlan kütüphane
#define bool int

struct sNode {//stack düðüm yapýsýdýr
	char data;
	struct sNode* next;
};

void push(struct sNode** top_ref, int new_data);// stack  bir öðeyi istiflemeye itme iþlevi
int pop(struct sNode** top_ref);
bool parantezCiftleri(char parantez1, char parantez2)//Karakter1 ve karakter2 parantezleri eþleþiyorsa 1 döndürür 
{
	if (parantez1=='('&& parantez2==')')
	{
		return 1;
	}
	else if (parantez1=='{'&& parantez2=='}')
	{
		return 1;

	}
	else if (parantez1=='['&& parantez2==']')
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
bool dengeliParantez(char orn[])//Ýfadede dengeli Parantez varsa 1 döndür
{
	int i = 0;
	struct sNode* stack = NULL;//Boþ bir karakter yýðýný bildirir
	while (orn[i])//Eþleþmeyi  parantezi kontrol etmek 
	{
		if (orn[i] == '{' || orn[i] == '(' || orn[i] == '[')
			push(&stack, orn[i]);
		if (orn[i] == '}' || orn[i] == ')' || orn[i] == ']')
		{
			if (stack == NULL) //Çiftsiz bir son parantez görürsek  sonra yanlýþ döndür
				return 0;
			else if (!parantezCiftleri(pop(&stack), orn[i]))//Üstteki öðeyi yýðýndan çýkar, deðilse bir çift karakter parantezi sonra bir uyumsuzluk. {(}gibi ifadeler için olur.
			{
				return 0;
			}
		}
		i++;
	}
	if (stack==NULL)
	{
		return 1;//parantez doðru kullanýlmýþ
	}
	else
	{
		return 0;// parantez doðru kullanýlmamýþtýr
	}
}
int main()
{
	char orn[100] = "{a*b(b*2)}[h+m])";//kullanýcýnýn girdiði ifade en fazla 100 karakter içerebilir
	if (dengeliParantez(orn))
	{
		printf("Parantezleriniz dogrudur\n");
	}
	else
	{
		printf("Parantezleriniz dogru degildir");
		return 0;
	}
}
void push(struct sNode** top_ref, int new_data)
{
	struct sNode* new_node
	= (struct sNode*)malloc(sizeof(struct sNode));
	if (new_node == NULL) {
		printf("Stack tasmistir");
		getchar();
		exit(0);
	}
	new_node->data = new_data;//veri girmek için
	new_node->next = (*top_ref);//eski listeyi yeni node baslatmak
	(*top_ref) = new_node;
}
int pop(struct sNode** top_ref)
{
	char son;
	struct sNode* top;
	if (*top_ref==NULL)//yýðýn boþ ise yani isEmpty() gibi düþünebiliriz
	{
		printf("Stack bostur");
		getchar();
		exit(0);
	}
	else
	{
		top = *top_ref;
		son = top->data;
		*top_ref = top->next;
		free(top);// eþitledikten sonra top degeri kullanamayýz.Eðer silmezsek hafýza yer kaplar.Ýstediðimiz zaman eriþemiyiz.Uzayda kaybolur.O yüzden silmeliyiz.
		return son;
	}
}