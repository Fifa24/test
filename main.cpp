#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
  string key,word,crypt;
  char convert_key;
  int val,decode,long_word,asc_val,long_key,j(-1),choice;
  cout<<"Choisir 1 pour entrer le texte clair \n: ";
  cout<<"Choisir 2 pour le texte qui se trouve dans un fichier: ";
  cin>>choice;
  switch (choice) {
  case 1:
      cout<<"Entrez la cle de cryptage : ";
      cin>>key;
      cout<<"Entrez le mot a crypter par cette cle : ";
      cin>>word;
      long_key=key.length();
      long_word=word.size();
      for(int i=0; i<long_word;i++){
          j+=1;
          if(j>long_key-1){
              j=0;
          }
          convert_key=int(key[j]);
          val =convert_key-65;
          decode=int(word[i]);
          if((decode+val)>90){
              int plus =(decode+val)-90;
              asc_val=65+plus-1;
          }
          else
          {
              asc_val=decode+val;
          }
          crypt+= char(asc_val);
      }
      cout<<"Le cryptage de "<<word<<" est :"<<crypt;
      break;
 case 2:
      fstream lecture("C:/Users/HP/Documents/crypto/crypto.txt",ios::in);
      string line;
      cout<<"Entrez la cle de cryptage : ";
       long_key=key.length();
      cin>>key;
      while(getline(lecture,line)){
          long_word=line.size();
          for(int i=0; i<long_word;i++){
              j+=1;
              if(j>long_key-1){
                  j=0;
              }
              convert_key=int(key[j]);
              val =convert_key-65;
              decode=int(line[i]);
              if((decode+val)>90){
                  int plus =(decode+val)-90;
                  asc_val=65+plus-1;
              }
              else
              {
                  asc_val=decode+val;
              }
              crypt+= char(asc_val);
          }
          cout<<"Le cryptage de "<<word<<" est :"<<crypt;
      }
      break;
  }

}
