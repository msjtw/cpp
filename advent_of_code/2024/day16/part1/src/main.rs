use priority_queue::PriorityQueue;
use std::io;

fn main() {
    let mut mmap: [[char; 150]; 150] = [['#'; 150]; 150];
    let mut s_x: usize = 0;
    let mut s_y: usize = 0;
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();
    for i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let line = line.trim();
        for k in 0..line.len() {
            mmap[i][k] = line.chars().nth(k).unwrap();
            if mmap[i][k] == 'S' {
                s_x = k;
                s_y = i;
            }
        }
    }

    // <: (0, -1)
    // ^: (-1, 0)
    // >: (0, 1)
    // v: (1, 0)
    let mut res = 0;
    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    let mut vis: [[bool; 150]; 150] = [[false; 150]; 150];
    let mut q = PriorityQueue::new();
    q.push((s_x, s_y, (0, 1)), 0);
    vis[s_y][s_x] = true;
    while !q.is_empty() {
        let ((x, y, dir), mut d) = q.pop().unwrap();
        d *= -1;
        vis[y][x] = true;
        for m_dir in dirs {
            let (dx, dy) = m_dir;
            if mmap[(y as i32 + dy) as usize][(x as i32 + dx) as usize] == '#' {
                continue;
            }
            if mmap[(y as i32 + dy) as usize][(x as i32 + dx) as usize] == 'E' {
                res = d;
                println!("{res}")
            }
            let new_move = ((x as i32 + dx) as usize, (y as i32 + dy) as usize, m_dir);
            if vis[new_move.1][new_move.0] {
                continue;
            }
            if dir == m_dir {
                q.push(new_move, -1 * (d + 1));
            } else {
                q.push(new_move, -1 * (d + 1001));
            }
        }
    }
    println!("{res}")
}
