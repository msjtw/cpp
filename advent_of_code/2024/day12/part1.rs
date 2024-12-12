use std::collections::VecDeque;
use std::io;

fn main() {
    let mut mmap: [[char; 142]; 142] = [['.'; 142]; 142];

    let n = 142;
    for i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let line = line.trim();
        for (k, c) in line.chars().enumerate() {
            mmap[i][k] = c;
        }
    }

    let mut res = 0;
    let mut vis: [[bool; 142]; 142] = [[false; 142]; 142];
    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    for i in 1..n - 1 {
        for k in 1..n - 1 {
            if vis[i][k] {
                continue;
            }
            let mut area = 1;
            let mut para = 0;
            let mut q: VecDeque<(usize, usize)> = VecDeque::new();
            q.push_back((i, k));
            vis[i][k] = true;
            while !q.is_empty() {
                let (a, b) = q[0];
                q.pop_front();
                for dir in dirs {
                    if mmap[(a as i32 + dir.0) as usize][(b as i32 + dir.1) as usize] == mmap[i][k]
                        && !vis[(a as i32 + dir.0) as usize][(b as i32 + dir.1) as usize]
                    {
                        vis[(a as i32 + dir.0) as usize][(b as i32 + dir.1) as usize] = true;
                        area += 1;
                        q.push_back(((a as i32 + dir.0) as usize, (b as i32 + dir.1) as usize));
                    } else if mmap[(a as i32 + dir.0) as usize][(b as i32 + dir.1) as usize]
                        != mmap[i][k]
                    {
                        para += 1;
                    }
                }
            }
            res += area * para;
        }
    }
    println!("{res}");
}
