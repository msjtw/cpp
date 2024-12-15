use std::io;

fn main() {
    let mut mmap: [[char; 50]; 50] = [['#'; 50]; 50];
    let (mut r_x, mut r_y) = (0, 0);
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();
    for i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        for k in 0..n {
            mmap[i][k] = line.chars().nth(k).unwrap();
            if mmap[i][k] == '@' {
                r_x = k;
                r_y = i;
            }
        }
    }
    let mut moves = String::new();
    io::stdin().read_line(&mut moves).unwrap();
    moves = moves.trim().to_string();
    for c in moves.chars() {
        if c == '^' {
            let mut diff = 0;
            while mmap[r_y - diff][r_x] != '#' && mmap[r_y - diff][r_x] != '.' {
                diff += 1;
            }
            if mmap[r_y - diff][r_x] == '.' {
                loop {
                    let tmp = mmap[r_y - diff][r_x];
                    mmap[r_y - diff][r_x] = mmap[r_y - diff + 1][r_x];
                    mmap[r_y - diff + 1][r_x] = tmp;
                    diff -= 1;
                    if diff == 0 {
                        break;
                    }
                }
                r_y -= 1;
            }
        } else if c == '>' {
            let mut diff = 0;
            while mmap[r_y][r_x + diff] != '#' && mmap[r_y][r_x + diff] != '.' {
                diff += 1;
            }
            if mmap[r_y][r_x + diff] == '.' {
                loop {
                    let tmp = mmap[r_y][r_x + diff];
                    mmap[r_y][r_x + diff] = mmap[r_y][r_x + diff - 1];
                    mmap[r_y][r_x + diff - 1] = tmp;
                    diff -= 1;
                    if diff == 0 {
                        break;
                    }
                }
                r_x += 1;
            }
        } else if c == 'v' {
            let mut diff = 0;
            while mmap[r_y + diff][r_x] != '#' && mmap[r_y + diff][r_x] != '.' {
                diff += 1;
            }
            if mmap[r_y + diff][r_x] == '.' {
                loop {
                    let tmp = mmap[r_y + diff][r_x];
                    mmap[r_y + diff][r_x] = mmap[r_y + diff - 1][r_x];
                    mmap[r_y + diff - 1][r_x] = tmp;
                    diff -= 1;
                    if diff == 0 {
                        break;
                    }
                }
                r_y += 1;
            }
        } else if c == '<' {
            let mut diff = 0;
            while mmap[r_y][r_x - diff] != '#' && mmap[r_y][r_x - diff] != '.' {
                diff += 1;
            }
            if mmap[r_y][r_x - diff] == '.' {
                loop {
                    let tmp = mmap[r_y][r_x - diff];
                    mmap[r_y][r_x - diff] = mmap[r_y][r_x - diff + 1];
                    mmap[r_y][r_x - diff + 1] = tmp;
                    diff -= 1;
                    if diff == 0 {
                        break;
                    }
                }
                r_x -= 1;
            }
        }
        // println!("move: {c}");
        // for i in 0..n {
        //     for k in 0..n {
        //         print!("{}", mmap[i][k]);
        //     }
        //     println!("");
        // }
    }
    let mut res = 0;
    for i in 0..n {
        for k in 0..n {
            if mmap[i][k] == 'O' {
                res += i * 100 + k;
            }
        }
    }
    print!("{}", res);
}
