#include <cstdio>
#define MAX_VALUE 80

class Polynomial{
    private:
        int degree;
        float coef[MAX_VALUE];
    public:
        Polynomial(){
            degree = 0;
        };

        bool isZero(){
            return degree == 0;
        };
        
        void read(){
            printf("다항식의 최고차항을 입력해주세요");
            scanf("%d", &degree);
            printf("각 항의 계수를 입력하세요 (총 %d개): ", degree + 1);

            for(int i = 0; i <= degree; i++){
                scanf( "%f", coef+i);
            }
        }

        void display(char *str=" Poly = "){
            printf("\t%sd", str);
            for (int i = 0; i <= degree; i++){
                printf("%5.1f x^%d + ", coef[i], degree-i);
            }
            printf("%4.1f\n", coef[degree]);
        }

        void negate(){
            for(int i = 0; i < degree; i++){
                coef[i] = -coef[i];
            }
        }

        void add(Polynomial p1, Polynomial p2){
            if(p1.degree > p2.degree){
                *this = p1;     // p1 다항식을 자기 객체에 복사
                for (int i = 0; i<=p2.degree; i++){
                    coef[i+(degree-p2.degree)] += p2.coef[i]; 
                }
            }
            else{
                *this = p2;
                for (int i = 0; i<=p1.degree; i++){
                    coef[i+(degree-p1.degree)] += p1.coef[i]; 
                }
            }
        }
        void mult(Polynomial p1, Polynomial p2){
            if(p1.degree > p2.degree){
                *this = p1;     // p1 다항식을 자기 객체에 복사
                for (int i = 0; i<=p2.degree; i++){
                    coef[i+(degree-p2.degree)] *= p2.coef[i]; 
                }
            }
            else{
                *this = p2;
                for (int i = 0; i<=p1.degree; i++){
                    coef[i+(degree-p1.degree)] *= p1.coef[i]; 
                }
            }
        }
};