#include <iostream>

int main(void){
  std::string nb1;
  std::string nb2;
  std::string result;
  int carry = 0;

  nb1 = "10000";
  nb2 = "66";

  std::string::reverse_iterator counter1 = nb1.rbegin();
  std::string::reverse_iterator counter2 = nb2.rbegin();

  for( ; counter1!=nb1.rend() && counter2!=nb2.rend(); counter1++, counter2++){
      int digit1 = counter1[0] - 48;
      int digit2 = counter2[0] - 48;
      
      int temp = (digit1 + digit2 + carry); 
      carry = temp / 10;
      result.insert(result.begin(),(temp) %10 + 48 );

  }
  while(counter1!=nb1.rend()){
    int digit1 = counter1[0] - 48;
    int temp = (digit1 + carry); 
    carry = temp / 10;
    result.insert(result.begin(),(temp) %10 + 48 );
    counter1++;
  }
  while(counter2!=nb2.rend()){
    int digit2 = counter2[0] - 48;
    int temp = (digit2 + carry); 
    carry = temp / 10;
    result.insert(result.begin(),(temp) %10 + 48 );
    counter2++;
  }
    if(carry!= 0){
       result.insert(result.begin(),(carry) %10 + 48 );
    }
  std::cout << result << std::endl;
}

/*
 bitshift é só mudar as casas decimais o tanto de vezes o numero que está a direita

  >> é a direita (aumenta o valor);
  << é a esquerda (diminui o valor);

  ex: 1234 >> 3 = 1 (pq perdeu três casas)
  ex: 1234 << 3 = 1234000 (pq ganhou três casas)

*/

//OBS: inicializar o construtor padrão com 0 pq estou usando string;

//OBS: em TODAS as operações começar de trás pra frente;