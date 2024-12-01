use std::io;

fn main() {
    let mut n = String::new(); 
    io::stdin().read_line(&mut n).expect("");
    let n: i32 = n.trim().parse().expect("");

    let mut arr1: Vec<usize> = Vec::new();
    let mut count = [0; 100000];

    for _i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("");
        let line = line.trim().split("   ");
        let line = line.collect::<Vec<&str>>();
        let a: usize = line[0].parse().expect("");
        let b: usize = line[1].parse().expect("");
        arr1.push(a);
        count[b] += 1;
    }

    let mut res: usize = 0;

    for i in 0..arr1.len() {
        res += arr1[i] * count[arr1[i]];
    }

    println!("{res}");
}
