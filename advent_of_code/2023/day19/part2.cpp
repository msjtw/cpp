#include<iostream>
#include<vector>
#include<map>

using namespace std;

typedef long long int ll;

struct rule{
    char cat;
    char sym;
    int val;
    string dest;
    bool no_con = false;
};

struct process{
    string name;
    vector<rule> rules;
};

struct val{
     int x_min, x_max;
     int m_min, m_max;
     int a_min, a_max;
     int s_min, s_max;
};

map<string, process> processes;

long long int all(string proc, val v){
    if(proc == "R")
        return 0;
    if(proc == "A"){
        long long int a = ll(v.x_max-v.x_min+1)*ll(v.m_max-v.m_min+1)*ll(v.a_max-v.a_min+1)*ll(v.s_max-v.s_min+1);
        cout << a << endl;
        return a;
    }
    long long int ret = 0;
    for(rule r : processes[proc].rules){
        if(r.no_con){
            ret += all(r.dest ,v);
        }
        else{
            if(r.cat == 'x'){
                    if(r.sym == '>'){
                        val nv = v;
                        nv.x_min = max(nv.x_min, r.val+1);
                        if(nv.x_max >= nv.x_min){
                            v.x_max = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                    else{
                        val nv = v;
                        nv.x_max = min(nv.x_max, r.val-1);
                        if(nv.x_max >= nv.x_min){
                            v.x_min = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                }
                if(r.cat == 'm'){
                    if(r.sym == '>'){
                        val nv = v;
                        nv.m_min = max(nv.m_min, r.val+1);
                        if(nv.m_max >= nv.m_min){
                            v.m_max = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                    else{
                        val nv = v;
                        nv.m_max = min(nv.m_max, r.val-1);
                        if(nv.m_max >= nv.m_min){
                            v.m_min = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                }
                if(r.cat == 'a'){
                    if(r.sym == '>'){
                        val nv = v;
                        nv.a_min = max(nv.a_min, r.val+1);
                        if(nv.a_max >= nv.a_min){
                            v.a_max = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                    else{
                        val nv = v;
                        nv.a_max = min(nv.a_max, r.val-1);
                        if(nv.a_max >= nv.a_min){
                            v.a_min = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                }
                if(r.cat == 's'){
                    if(r.sym == '>'){
                        val nv = v;
                        nv.s_min = max(nv.s_min, r.val+1);
                        if(nv.s_max >= nv.s_min){
                            v.s_max = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                    else{
                        val nv = v;
                        nv.s_max = min(nv.s_max, r.val-1);
                        if(nv.s_max >= nv.s_min){
                            v.s_min = r.val;
                            ret += all(r.dest, nv);
                        }
                    }
                }
        }
    }
    //cout << ret << endl;
    return ret;
}

int main(){
    int n;
    cin >> n;
    processes["A"] = process{.name="A"};
    processes["R"] = process{.name="R"};
    while(n --> 0){
        process proc;
        cin >> proc.name;
        int r;
        cin >> r;
        while(r --> 0){
            rule rule;
            string s_rule;
            cin >> s_rule;
            if(s_rule.find('>') == string::npos and s_rule.find('<') == string::npos){
                rule.dest = s_rule;
                rule.no_con = true;
            }
            else{
                rule.cat = s_rule[0];
                rule.sym = s_rule[1];
                string v = s_rule.substr(2,s_rule.find(':')-2);
                rule.val = stoi(v);
                rule.dest = s_rule.substr(s_rule.find(':') + 1);
            }
            proc.rules.push_back(rule);
        }
        processes[proc.name] = proc;
    }

    cout << all("in", {1,4000,1,4000,1,4000,1,4000});

    return 0;
}