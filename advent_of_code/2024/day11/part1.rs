use std::io;

fn dp(it: usize, num: num, cache: &)

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut stones: Vec<i64> = line
        .trim()
        .split(" ")
        .map(|val| val.parse().unwrap())
        .collect();

    let mut iteration = 25;
    while iteration > 0 {
        println!("{iteration}:");
        let mut procces = Vec::new();
        for stone in stones {
            if stone == 0 {
                procces.push(stone + 1);
            } else if stone.to_string().len() % 2 == 0 {
                let split: usize = stone.to_string().len() / 2;
                let stone1 = &stone.to_string()[..split];
                let stone1: i64 = stone1.parse().unwrap();
                let stone2 = &stone.to_string()[split..];
                let stone2: i64 = stone2.parse().unwrap();
                procces.push(stone1);
                procces.push(stone2);
            } else {
                procces.push(stone * 2024);
            }
        }
        for stone in &procces {
            print!("{stone} ");
        }
        println!("");
        stones = procces;
        iteration -= 1;
    }

    println!("{}", stones.len());
}
