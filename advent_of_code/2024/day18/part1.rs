use std::collections::VecDeque;
use std::io;

fn main() {
    let mut mmap: [[char; 85]; 85] = [['#'; 85]; 85];
    let mut dist: [[i32; 85]; 85] = [[100000; 85]; 85];
    for i in 1..72 {
        for k in 1..72 {
            mmap[i][k] = '.';
        }
    }

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    for i in 0..n {
        let mut pos = String::new();
        io::stdin().read_line(&mut pos).unwrap();
        let (x, y) = pos.split_once(' ').unwrap();
        let x: usize = x.trim().parse().unwrap();
        let y: usize = y.trim().parse().unwrap();
        if i < 1024 {
            mmap[y + 1][x + 1] = '#';
        }
    }

    for i in 1..72 {
        for k in 1..72 {
            print!("{}", mmap[i][k]);
        }
        println!("");
    }

    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    let mut q = VecDeque::new();
    q.push_back((1, 1));
    dist[1][1] = 0;
    while !q.is_empty() {
        let a = q.pop_front().unwrap();
        for dir in dirs {
            let new_p = ((a.0 as i32 + dir.0) as usize, (a.1 as i32 + dir.1) as usize);
            if mmap[new_p.0][new_p.1] != '#' && dist[a.0][a.1] + 1 < dist[new_p.0][new_p.1] {
                dist[new_p.0][new_p.1] = dist[a.0][a.1] + 1;
                q.push_back(new_p);
            }
        }
    }
    println!("{}", dist[71][71]);
}
