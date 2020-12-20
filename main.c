#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdarg.h>
const char matrix_bigram_strings[10][3] ={"TH", "HE", "IN", "ER", "AN",
                                          "EN", "CH", "DE", "EI", "TE"};

const char matrix_trigram_strings[10][4]={"THE", "AND", "ING", "ENT", "ION",
                                          "DER", "SCH", "ICH", "NDE", "DIE"};

const char languages[2][8]={"ENGLISH", "GERMAN"};

//Ingilizce dilinin frekans degerleri
const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61,
                                1.13, 0.01, 0.01, 0.01, 0.01,
                                1.81, 0.73, 0.72, 0.42, 0.42,
                                0.01, 0.01, 0.01, 0.01, 0.01 };

//Almanca dilinin frekans degerleri
const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07,
                                 3.61, 2.36, 2.31, 1.98, 1.98,
                                 0.01, 0.01, 0.01, 0.01, 0.01,
                                 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};

void filter_str(char str[]) //Yabanci karakterleri metinden temizleyen fonksiyon
{
    int i=0;
    int fark = 'a' - 'A';

    while (str[i] != '\0') {

        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str [i];
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= fark;
        } else if (str[i]=='\n'){
            str[i] = ' ';
        }else{
            str[i] = ' ';
        }
        printf("%c", str[i]);
        i++;
    }

printf("\n\n*************************\n");
}


void calculate_frequencies_bi(char str[]) //Metindeki bigram sayisini kontrol eden fonksiyon
{
    float sonuc_th,sonuc_he,sonuc_in,sonuc_er,sonuc_an,sonuc_en,sonuc_ch,sonuc_de,sonuc_ei,sonuc_te;
    sonuc_th=sonuc_he=sonuc_in=sonuc_er=sonuc_an=sonuc_en=sonuc_ch=sonuc_de=sonuc_ei=sonuc_te=0;

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==matrix_bigram_strings[0][0]) //Alinan metindeki karakterler ile bigram matrislerinin tek tek kontrolu
            if(str[i+1]==matrix_bigram_strings[0][1])
                sonuc_th+=1;
        if(str[i]==matrix_bigram_strings[1][0])
            if(str[i+1]==matrix_bigram_strings[1][1])
                sonuc_he+=1;
        if(str[i]==matrix_bigram_strings[2][0])
            if(str[i+1]==matrix_bigram_strings[2][1])
                sonuc_in+=1;
        if(str[i]==matrix_bigram_strings[3][0])
            if(str[i+1]==matrix_bigram_strings[3][1])
                sonuc_er+=1;
        if(str[i]==matrix_bigram_strings[4][0])
            if(str[i+1]==matrix_bigram_strings[4][1])
                sonuc_an+=1;
         if(str[i]==matrix_bigram_strings[5][0])
            if(str[i+1]==matrix_bigram_strings[5][1])
                sonuc_en+=1;
        if(str[i]==matrix_bigram_strings[6][0])
            if(str[i+1]==matrix_bigram_strings[6][1])
                sonuc_ch+=1;
        if(str[i]==matrix_bigram_strings[7][0])
            if(str[i+1]==matrix_bigram_strings[7][1])
                sonuc_de+=1;
        if(str[i]==matrix_bigram_strings[8][0])
            if(str[i+1]==matrix_bigram_strings[8][1])
                sonuc_ei+=1;
        if(str[i]==matrix_bigram_strings[9][0])
            if(str[i+1]==matrix_bigram_strings[9][1])
                sonuc_te+=1;
    }

    calculated_frequencies[0]=sonuc_th;
    calculated_frequencies[1]=sonuc_he;
    calculated_frequencies[2]=sonuc_in;
    calculated_frequencies[3]=sonuc_er;
    calculated_frequencies[4]=sonuc_an;
    calculated_frequencies[5]=sonuc_en;
    calculated_frequencies[6]=sonuc_ch;
    calculated_frequencies[7]=sonuc_de;
    calculated_frequencies[8]=sonuc_ei;
    calculated_frequencies[9]=sonuc_te;

    printf("\n\tBIGRAM\n\n");
    printf("TH : %.2f \n",sonuc_th);
    printf("HE : %.2f \n",sonuc_he);
    printf("IN : %.2f \n",sonuc_in);
    printf("ER : %.2f \n",sonuc_er);
    printf("AN : %.2f \n",sonuc_an);
    printf("EN : %.2f \n",sonuc_en);
    printf("CH : %.2f \n",sonuc_ch);
    printf("DE : %.2f \n",sonuc_de);
    printf("EI : %.2f \n",sonuc_ei);
    printf("TE : %.2f \n",sonuc_te);
    printf("\n*************************\n\n");
}

void calculate_frequencies_tri(char str[]) //Metindeki trigram sayisini kontrol eden fonksiyon
{
    float sonuc_the,sonuc_and,sonuc_ing,sonuc_ent,sonuc_ion,sonuc_der,sonuc_sch,sonuc_ich,sonuc_nde,sonuc_die;
    sonuc_the=sonuc_and=sonuc_ing=sonuc_ent=sonuc_ion=sonuc_der=sonuc_sch=sonuc_ich=sonuc_nde=sonuc_die=0;

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==matrix_trigram_strings[0][0]) //Alinan metindeki karakterler ile trigram matrislerinin tek tek kontrolu
            if(str[i+1]==matrix_trigram_strings[0][1])
                if(str[i+2]==matrix_trigram_strings[0][2])
                sonuc_the+=1;
        if(str[i]==matrix_trigram_strings[1][0])
            if(str[i+1]==matrix_trigram_strings[1][1])
                if(str[i+2]==matrix_trigram_strings[1][2])
                sonuc_and+=1;
        if(str[i]==matrix_trigram_strings[2][0])
            if(str[i+1]==matrix_trigram_strings[2][1])
                if(str[i+2]==matrix_trigram_strings[2][2])
                sonuc_ing+=1;
        if(str[i]==matrix_trigram_strings[3][0])
            if(str[i+1]==matrix_trigram_strings[3][1])
                if(str[i+2]==matrix_trigram_strings[3][2])
                sonuc_ent+=1;
        if(str[i]==matrix_trigram_strings[4][0])
            if(str[i+1]==matrix_trigram_strings[4][1])
                if(str[i+2]==matrix_trigram_strings[4][2])
                sonuc_ion+=1;
         if(str[i]==matrix_trigram_strings[5][0])
            if(str[i+1]==matrix_trigram_strings[5][1])
                if(str[i+2]==matrix_trigram_strings[5][2])
                sonuc_der+=1;
        if(str[i]==matrix_trigram_strings[6][0])
            if(str[i+1]==matrix_trigram_strings[6][1])
                if(str[i+2]==matrix_trigram_strings[6][2])
                sonuc_sch+=1;
        if(str[i]==matrix_trigram_strings[7][0])
            if(str[i+1]==matrix_trigram_strings[7][1])
                if(str[i+2]==matrix_trigram_strings[7][2])
                sonuc_ich+=1;
        if(str[i]==matrix_trigram_strings[8][0])
            if(str[i+1]==matrix_trigram_strings[8][1])
                if(str[i+2]==matrix_trigram_strings[8][2])
                sonuc_nde+=1;
        if(str[i]==matrix_trigram_strings[9][0])
            if(str[i+1]==matrix_trigram_strings[9][1])
                if(str[i+2]==matrix_trigram_strings[9][2])
                sonuc_die+=1;
    }

    calculated_frequencies[10]=sonuc_the;
    calculated_frequencies[11]=sonuc_and;
    calculated_frequencies[12]=sonuc_ing;
    calculated_frequencies[13]=sonuc_ent;
    calculated_frequencies[14]=sonuc_ion;
    calculated_frequencies[15]=sonuc_der;
    calculated_frequencies[16]=sonuc_sch;
    calculated_frequencies[17]=sonuc_ich;
    calculated_frequencies[18]=sonuc_nde;
    calculated_frequencies[19]=sonuc_die;

    printf("\tTRIGRAM\n\n");
    printf("THE : %.2f \n",sonuc_the);
    printf("AND : %.2f \n",sonuc_and);
    printf("ING : %.2f \n",sonuc_ing);
    printf("ENT : %.2f \n",sonuc_ent);
    printf("ION : %.2f \n",sonuc_ion);
    printf("DER : %.2f \n",sonuc_der);
    printf("SCH : %.2f \n",sonuc_sch);
    printf("ICH : %.2f \n",sonuc_ich);
    printf("NDE : %.2f \n",sonuc_nde);
    printf("DIE : %.2f \n",sonuc_die);
    printf("\n*************************\n");
}

void calculate_distances(float k,...) //Bulunan bigram ve trigramlara gore frekanslarini hesaplayan fonksiyon
{
    printf("\n\tCALCULATED FREQUENCIES\n\n");

    va_list frequencies;
    va_start (frequencies,k);
    float eng=0.0;


    for(int m=0;m<20;m++)
    {
        double anlik_deger=0;
        anlik_deger=frequency_eng[m]*va_arg(frequencies,double);
        eng=eng+anlik_deger;
    }
    printf("ENGLISH : %.3f\n",eng);
    distances [0]=eng;

    va_end(frequencies);

    va_start (frequencies,k);
    float germ=0.0;

    for(int m=0;m<20;m++)
    {
        double anlik_deger=0;
        anlik_deger=frequency_germ[m]*va_arg(frequencies,double);
        germ=germ+anlik_deger;
    }
    printf("GERMAN  : %.3f\n",germ);
    distances [1]=germ;

    va_end(frequencies);
    printf("\n**************************\n\n");

}

void detect_lang(float language[]) //Hesaplanan frekanslari kiyaslayarak dili tahmin edip ekrana yazdiran fonksiyon
{
    if(language[0]>language[1])
    {
        printf("LANGUAGE ---> ENGLISH\n");
        }
    else if(language[0]<language[1])
{
        printf("LANGUAGE ---> GERMAN\n");
        }
    else
     {
        printf("INCORRECT ENTRY\n");
        }
    printf("\n**************************\n");
}

int main()
{

    char metin[999999];
    printf("TEXT:\n\n");
    gets(metin);

    printf("\n**************************");
    printf("\n\nFILTERED TEXT:\n\n");
    filter_str(metin);
    calculate_frequencies_bi(metin);
    calculate_frequencies_tri(metin);


    calculate_distances(20,calculated_frequencies[0],
                        calculated_frequencies[1],calculated_frequencies[2],
                        calculated_frequencies[3],calculated_frequencies[4],
                        calculated_frequencies[5],calculated_frequencies[6],
                        calculated_frequencies[7],calculated_frequencies[8],
                        calculated_frequencies[9],calculated_frequencies[10],
                        calculated_frequencies[11],calculated_frequencies[12],
                        calculated_frequencies[13],calculated_frequencies[14],
                        calculated_frequencies[15],calculated_frequencies[16],
                        calculated_frequencies[17],calculated_frequencies[18],
                        calculated_frequencies[19],calculated_frequencies[20]);

    detect_lang(distances);

    system("pause");
    return 0;
}
