use std::io;

fn print_robots(robots: &Vec<(i32, i32, i32, i32)>, width: i32, height: i32) {
    let mut robot_count: [[i32; 101]; 103] = [[0; 101]; 103];
    for robot in robots {
        robot_count[robot.1 as usize][robot.0 as usize] += 1;
    }
    let mut n = 0;
    let dirs = [(-1, 0), (1, 0), (0, -1), (0, -1)];
    for i in 1..(height - 1) as usize {
        for k in 1..(width - 1) as usize {
            if robot_count[i][k] == 1 {
                for dir in dirs {
                    if robot_count[(i as i32 + dir.0) as usize][(k as i32 + dir.1) as usize] == 1 {
                        n += 1;
                    }
                }
            }
        }
    }
    println!("{n}");
}

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();
    let mut robots = Vec::new();
    for _i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let mut r: (i32, i32, i32, i32) = (0, 0, 0, 0);
        let line: Vec<&str> = line.split(" ").collect();
        r.0 = line[0].trim().parse().unwrap();
        r.1 = line[1].trim().parse().unwrap();
        r.2 = line[2].trim().parse().unwrap();
        r.3 = line[3].trim().parse().unwrap();
        robots.push(r);
    }

    let width = 101;
    let height = 103;
    for it in 1..10000 {
        for i in 0..robots.len() {
            let mut nx = robots[i].0 + robots[i].2;
            nx = ((nx % width) + width) % width;
            let mut ny = robots[i].1 + robots[i].3;
            ny = ((ny % height) + height) % height;
            robots[i] = (nx, ny, robots[i].2, robots[i].3);
        }
        print_robots(&robots, width, height);
    }
}
