use std::io;

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
    let mut robot_count: [[i32; 101]; 103] = [[0; 101]; 103];
    for r in robots {
        let (mut x, mut y, px, py) = r;
        x = (((x + 100 * px) % width) + width) % width;
        y = (((y + 100 * py) % height) + height) % height;
        robot_count[y as usize][x as usize] += 1;
    }

    // for i in 0..height as usize {
    //     for k in 0..width as usize {
    //         print!("{}", robot_count[i][k]);
    //     }
    //     println!("");
    // }

    let mut res = 1;
    let mut count = 0;
    for i in 0..(height / 2) {
        for k in 0..(width / 2) {
            count += robot_count[i as usize][k as usize];
        }
    }
    print!("{count} ");
    res *= count;
    count = 0;
    for i in ((height / 2) + 1)..height {
        for k in 0..(width / 2) {
            count += robot_count[i as usize][k as usize];
        }
    }
    print!("{count} ");
    res *= count;
    count = 0;
    for i in 0..height / 2 {
        for k in ((width / 2) + 1)..width {
            count += robot_count[i as usize][k as usize];
        }
    }
    print!("{count} ");
    res *= count;
    count = 0;
    for i in ((height / 2) + 1)..height {
        for k in ((width / 2) + 1)..width {
            count += robot_count[i as usize][k as usize];
        }
    }
    println!("{count} ");
    res *= count;
    println!("{res}");
}
