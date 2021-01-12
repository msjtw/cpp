# Wstęp

## rozimiay

|10^|2^|
|:---:|:---:|
| 10^5 | 2^17 |
| 2*10^5 | 2^18 |
| 5*10^5 | 2^19 |
| 10^6 | 2^20 |

# Funkcje

## punkt - przedzial

```c++
void insert(int drz_prz[], int id, int val){
    int i = id + base;
    drz_prz[i] = val;
    while(i > 0){
        i >>= 1;
        drz_prz[i] = drz_prz[2*i] + drz_prz[2*i+1];
    }
}
```
```c++
int query(int drz_prz[], int p, int q){
    int ret = 0;
    p = p + base -1;
    q = q + base +1;
    while(p/2 != q/2){
        if(p % 2 == 0)
            ret += drz_prz[p+1];
        if(q % 2 == 1)
            ret += drz_prz[q-1];
        p >>= 1;
        q >>= 1;
    } 
    return ret;
}
```

## przedzial - punkt

```c++
void insert(int drz_prz[], int p, int q, int w){
    p += base-1;
    q += base+1;
    while(p/2 != q/2){
        if(p % 2 == 0)
            drz_prz[p+1] += w;
        if(q % 2 == 1)
            drz_prz[q-1] += w;
        p >>= 1;
        q >>= 1;
    }
}
```
```c++
int query(int drz_prz[], int id){
    int ret = 0;
    id += base;
    while(id > 0){
        ret += drz_prz[id];
        id >>= 1;
    }
    return ret;
}
```
## przedział - przedział

### (+,+)
```c++
void insert(node drz_prz[], int p, int q, int w){
    int len = 1;
    p += base ;
    q += base ;
    drz_prz[p].wart += w;
    drz_prz[p].suma += w;
    if(p != q){
        drz_prz[q].suma += w;
        drz_prz[q].wart += w;
    }
    while(q > 0){
        if(p/2 != q/2){
            if(p%2 == 0){
                drz_prz[p+1].wart += w;
                drz_prz[p+1].suma += len*w;
            }
            if(q%2 == 1){
                drz_prz[q-1].wart += w;
                drz_prz[q-1].suma += len*w;
            }
        }
        if(p < base ){
            drz_prz[p].suma = drz_prz[2*p].suma + drz_prz[2*p+1].suma + len*drz_prz[p].wart;
            drz_prz[q].suma = drz_prz[2*q].suma + drz_prz[2*q+1].suma + len*drz_prz[q].wart;
        }
        p >>= 1;
        q >>= 1;
        len <<= 1;
    }
}

```
```c++
int query(node drz_prz[], int p, int q){
    int ret = 0;
    int l_len = 0, r_len = 0, len = 1;
    p += base -1;
    q += base +1;
    while(q > 0){
        ret += drz_prz[p].wart*l_len + drz_prz[q].wart*r_len;
        if(p/2 != q/2){
            if(p%2 == 0){
                ret += drz_prz[p+1].suma;
                l_len += len;
            }
            if(q%2 == 1){
                ret += drz_prz[q-1].suma;
                r_len += len;
            }
        }
        p >>= 1;
        q >>= 1;
        len <<= 1;
    }
    return ret;
}
```

### (+, max)
```c++
void insert(node drz_prz[], int p, int q, int w){
    p += base ;
    q += base ;
    drz_prz[p].wart += w;
    drz_prz[p].max += w;
    if(p != q){
        drz_prz[q].wart += w;
        drz_prz[q].max += w;
    }
    while(p > 0){
        if(p/2 != q/2){
            if(!(p&1)){
                drz_prz[p+1].wart += w;
                drz_prz[p+1].max += w;
            }
            if(q&1){
                drz_prz[q-1].wart += w;
                drz_prz[q-1].max += w;
            }
        }
        if(p < base ){
            drz_prz[p].max = max(drz_prz[2*p].max + drz_prz[p].wart, drz_prz[2*p+1].max + drz_prz[p].wart);
            drz_prz[q].max = max(drz_prz[2*q].max + drz_prz[q].wart, drz_prz[2*q+1].max + drz_prz[q].wart);
        }
        p >>= 1;
        q >>= 1;
    }
}
```
```c++
int query(node drz_prz[], int p, int q){
    p += base;
    q += base;
    int l_max = 0;
    int r_max = 0;
    while(p > 0){
        l_max += drz_prz[p].wart;
        r_max += drz_prz[q].wart;
        if(p/2 != q/2){
            if(!(p&1)){
                l_max = max(l_max, drz_prz[p+1].max);
            }
            if(q&1){
                r_max = max(r_max, drz_prz[q-1].max);
            }
        }
        p >>= 1;
        q >>= 1;
    }
    return max(r_max, l_max);
}
```