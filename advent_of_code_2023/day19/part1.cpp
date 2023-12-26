#include<iostream>
#include<vector>
#include<map>

using namespace std;

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

struct thing{
    int x, m, a ,s;
};

map<string, process> processes;
vector<thing> things;

vector<thing> accepted;
vector<thing> rejected;

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
    cin >> n;
    while(n --> 0){
        thing t;
        cin >> t.x >> t.m >> t.a >> t.s;
        things.push_back(t);
    }

    for(thing th: things){
        process proc = processes["in"];
        cout << endl << th.a << endl;
        while(true){
            cout << proc.name << " ";
            if(proc.name == "A"){
                accepted.push_back(th);
                break;
            }
            if(proc.name == "R"){
                rejected.push_back(th);
                break;
            }
            for(rule r : proc.rules){
                if(r.no_con){
                    proc = processes[r.dest];
                    break;
                }
                if(r.cat == 'x'){
                    if(r.sym == '>'){
                        if(th.x > r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                    else{
                        if(th.x < r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                }
                if(r.cat == 'm'){
                    if(r.sym == '>'){
                        if(th.m > r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                    else{
                        if(th.m < r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                }
                if(r.cat == 'a'){
                    if(r.sym == '>'){
                        if(th.a > r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                    else{
                        if(th.a < r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                }
                if(r.cat == 's'){
                    if(r.sym == '>'){
                        if(th.s > r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                    else{
                        if(th.s < r.val){
                            proc = processes[r.dest];
                            break;
                        }
                        else{
                            continue;;
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    
    for(thing th : accepted){
        res += th.a + th.m + th.s + th.x;
    }

    cout << res;

    return 0;
}