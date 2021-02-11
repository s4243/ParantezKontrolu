#include<stdio.h>
#include<stdlib.h>//malloc i�in kullan�lan k�t�phane
#define bool int

struct sNode {//stack d���m yap�s�d�r
	char data;
	struct sNode* next;
};

void push(struct sNode** top_ref, int new_data);// stack  bir ��eyi istiflemeye itme i�levi
int pop(struct sNode** top_ref);
bool parantezCiftleri(char parantez1, char parantez2)//Karakter1 ve karakter2 parantezleri e�le�iyorsa 1 d�nd�r�r 
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
bool dengeliParantez(char orn[])//�fadede dengeli Parantez varsa 1 d�nd�r
{
	int i = 0;
	struct sNode* stack = NULL;//Bo� bir karakter y���n� bildirir
	while (orn[i])//E�le�meyi  parantezi kontrol etmek 
	{
		if (orn[i] == '{' || orn[i] == '(' || orn[i] == '[')
			push(&stack, orn[i]);
		if (orn[i] == '}' || orn[i] == ')' || orn[i] == ']')
		{
			if (stack == NULL) //�iftsiz bir son parantez g�r�rsek  sonra yanl�� d�nd�r
				return 0;
			else if (!parantezCiftleri(pop(&stack), orn[i]))//�stteki ��eyi y���ndan ��kar, de�ilse bir �ift karakter parantezi sonra bir uyumsuzluk. {(}gibi ifadeler i�in olur.
			{
				return 0;
			}
		}
		i++;
	}
	if (stack==NULL)
	{
		return 1;//parantez do�ru kullan�lm��
	}
	else
	{
		return 0;// parantez do�ru kullan�lmam��t�r
	}
}
int main()
{
	char orn[100] = "{a*b(b*2)}[h+m])";//kullan�c�n�n girdi�i ifade en fazla 100 karakter i�erebilir
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
	new_node->data = new_data;//veri girmek i�in
	new_node->next = (*top_ref);//eski listeyi yeni node baslatmak
	(*top_ref) = new_node;
}
int pop(struct sNode** top_ref)
{
	char son;
	struct sNode* top;
	if (*top_ref==NULL)//y���n bo� ise yani isEmpty() gibi d���nebiliriz
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
		free(top);// e�itledikten sonra top degeri kullanamay�z.E�er silmezsek haf�za yer kaplar.�stedi�imiz zaman eri�emiyiz.Uzayda kaybolur.O y�zden silmeliyiz.
		return son;
	}
}