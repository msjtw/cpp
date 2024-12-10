use std::collections::VecDeque;
use std::io;

fn main() {
    let mut topo: [[i32; 45]; 45] = [[0; 45]; 45];

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    let mut trailheads: Vec<(usize, usize)> = Vec::new();

    for i in 0usize..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let line = line.trim();
        for k in 0usize..line.len() {
            topo[i][k] = line.chars().nth(k).unwrap() as i32 - '0' as i32;
            if topo[i][k] == 0 {
                trailheads.push((i, k));
            }
        }
    }
    let mut res = 0;
    let dirs: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    let mut queue: VecDeque<(usize, usize)> = VecDeque::new();
    for start in trailheads {
        queue.push_back(start);
        while !queue.is_empty() {
            let a = queue[0];
            queue.pop_front();
            if topo[a.0][a.1] == 9 {
                res += 1;
            }
            for dir in dirs {
                if a.0 as i32 + dir.0 < 0
                    || a.0 as i32 + dir.0 >= n as i32
                    || a.1 as i32 + dir.1 < 0
                    || a.1 as i32 + dir.1 >= n as i32
                {
                    continue;
                }
                if topo[a.0][a.1] + 1
                    == topo[(a.0 as i32 + dir.0) as usize][(a.1 as i32 + dir.1) as usize]
                {
                    queue.push_back(((a.0 as i32 + dir.0) as usize, (a.1 as i32 + dir.1) as usize));
                }
            }
        }
    }
    println!("{}", res);
}
