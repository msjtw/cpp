use std::io;

extern crate nalgebra as na;
use na::{min, Matrix2, Vector2};

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();
    let mut res: i128 = 0;
    for _i in 0..n {
        let mut button_a = String::new();
        let mut button_b = String::new();
        let mut prize = String::new();
        io::stdin().read_line(&mut button_a).unwrap();
        io::stdin().read_line(&mut button_b).unwrap();
        io::stdin().read_line(&mut prize).unwrap();
        let (ax, ay) = button_a.split_once(" ").unwrap();
        let (bx, by) = button_b.split_once(" ").unwrap();
        let (prize_x, prize_y) = prize.split_once(" ").unwrap();
        let a: (f64, f64) = (ax.trim().parse().unwrap(), ay.trim().parse().unwrap());
        let b: (f64, f64) = (bx.trim().parse().unwrap(), by.trim().parse().unwrap());
        let p: (f64, f64) = (
            prize_x.trim().parse().unwrap(),
            prize_y.trim().parse().unwrap(),
        );
        let mut m_a = Matrix2::new(a.0, b.0, a.1, b.1);
        let m_b = Vector2::new(p.0 + 10000000000000.0, p.1 + 10000000000000.0);
        m_a.try_inverse_mut();
        let x = m_a * m_b;
        let (x1, x2) = (x[(0, 0)], x[(1, 0)]);
        println!("{x1} {x2} ");
        print!(
            "{} {}   ",
            (x1 - x1.trunc()).abs().min((x1.ceil() - x1).abs()),
            (x2 - x2.trunc()).abs().min((x2.ceil() - x2).abs()),
        );
        if (x1 - x1.trunc()).abs().min((x1.ceil() - x1).abs()) < 0.0001
            && (x2 - x2.trunc()).abs().min((x2.ceil() - x2).abs()) < 0.0001
        {
            print!("OK");
            res += (x1 + 0.1) as i128 * 3 + (x2 + 0.1) as i128;
        }
        println!();
        println!();
    }
    println!("{res}")
}
