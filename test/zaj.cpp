#include <iostream>

int len[2];
int slowa[2][15001];
int last[2][15001];
int row[15001];
int equal[15001];


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>len[0]>>len[1];
	for(int j=0;j<2;j++)
		for(int i=1;i<=len[j];i++){
			std::cin>>slowa[j][i];
			last[j][i]=0;
			for(int k=i-1;k>0;k--){
				if(slowa[j][i]==slowa[j][k]){
					last[j][i]=k;
					break;
				}
			}
		}
	
	for(int i=1;i<=len[0];i++){
        if(last[0][i]!=0){
            for(int j=1;j<=len[1];j++){
                if(row[j-1]>row[j] || (slowa[0][i]==slowa[1][j] && last[1][j]!=0 && row[j]==row[last[1][j]-1] && equal[last[1][j]-1]<last[0][i] ))
                    row[j]++, equal[j]=i;
            }
        }
	}
	std::cout<<row[len[1]]*2<<std::endl;
}