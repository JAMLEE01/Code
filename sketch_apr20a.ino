#二进制时钟
int h = 0; #时
int m = 0; #分
int s = 0; #秒
#初始化引脚
void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}
#展示代码
void display(int h, int m, int s){
  for(int i = 0; i < 167; i++){
    digitalWrite(25, HIGH);
    display1(h / 10);
    digitalWrite(13, LOW);
    delay(1);
    digitalWrite(13, HIGH);
    display1(h % 10);
    digitalWrite(12, LOW);
    delay(1);
    digitalWrite(12, HIGH);
    display1(m / 10);
    digitalWrite(14, LOW);
    delay(1);
    digitalWrite(14, HIGH);
    display1(m % 10);
    digitalWrite(27, LOW);
    delay(1);
    digitalWrite(27, HIGH);
    display1(s / 10);
    digitalWrite(26, LOW);
    delay(1);
    digitalWrite(26, HIGH);
    display1(s % 10);
    digitalWrite(25, LOW);
    delay(1);
  }
}

void display1(int num){
  if(num == 0){
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
  }else if(num == 1){
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
  }else if(num == 2){
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
  }else if(num == 3){
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
  }else if(num == 4){
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }else if(num == 5){
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }else if(num == 6){
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }else if(num == 7){
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }else if(num == 8){
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
  }else if(num == 9){
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
  }
}
#主程序loop
void loop() {
  display(h, m, s);
  s++;
  if(s == 60){
    m++;
    s = 0;
    if(m == 60){
      h++;
      m = 0;
      if(h == 24){
        h = 0;
      }
    }
  }
}
