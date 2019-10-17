#include <stdio.h>

const int MAX = 1e6;
const int PAGE_FRAME = 10;  

int n, full_cnt, hit, miss;
int page_fr[PAGE_FRAME], in_page_fr[MAX], newness[MAX]; 

int main(){
	freopen("input.txt", "r", stdin);

	for(int i = 0; i < MAX; i++)
		newness[i] = -1;

	for(int i = 0; i < PAGE_FRAME; i++) 
		page_fr[i] = -1;

	while(scanf("%d", &n) == 1) {
		if(in_page_fr[n] != 1) {
			if(full_cnt == PAGE_FRAME) { 
				int mx_newness = 0, mx_newness_id;
				for(int i = 0; i < PAGE_FRAME; i++) { 
					if(newness[page_fr[i]] > mx_newness) {
						mx_newness_id = i; 
						mx_newness = newness[page_fr[i]];
					}
					newness[page_fr[i]]++; 
				}
				newness[page_fr[mx_newness_id]] = -1;
				in_page_fr[page_fr[mx_newness_id]] = 0;
				newness[n] = 0;
				in_page_fr[n] = 1;
				page_fr[mx_newness_id] = n;	
			}
			else { 
				newness[n] = 0;
				in_page_fr[n] = 1;
				page_fr[full_cnt] = n; 
				for(int i = 0; i < full_cnt; i++){ 
					newness[page_fr[i]]++;
				}
				full_cnt++;
			}
			miss++;
		}
		else { 
			if(newness[n]){ 
				for(int i = 0; i < PAGE_FRAME; i++) {  
					if(newness[page_fr[i]] < newness[n] && page_fr[i] != -1)
						newness[page_fr[i]]++;
				}
				newness[n] = 0; 
			}
			hit++;
		}
	}
	printf("hit/miss ratio: %f", hit * 1.0 / miss); 

	return 0;
}