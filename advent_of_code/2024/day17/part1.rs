use std::io;

fn main() {
    let mut reg_a = String::new();
    let mut reg_b = String::new();
    let mut reg_c = String::new();
    io::stdin().read_line(&mut reg_a).unwrap();
    io::stdin().read_line(&mut reg_b).unwrap();
    io::stdin().read_line(&mut reg_c).unwrap();
    let mut reg_a: i32 = reg_a.trim().parse().unwrap();
    let mut reg_b: i32 = reg_b.trim().parse().unwrap();
    let mut reg_c: i32 = reg_c.trim().parse().unwrap();

    let mut instructions = String::new();
    io::stdin().read_line(&mut instructions).unwrap();
    let instructions: Vec<&str> = instructions.split(" ").collect();

    let mut i: i32 = 0;
    while i < instructions.len() as i32 {
        let instr: i32 = instructions[i as usize].trim().parse().unwrap();
        let operand: i32 = instructions[(i + 1) as usize].trim().parse().unwrap();
        // println!("{instr} {operand}");
        // println!("{reg_a} {reg_b} {reg_c}");
        match instr {
            0 => {
                let ppow: u32 = match operand {
                    4 => reg_a,
                    5 => reg_b,
                    6 => reg_c,
                    i32::MIN..=3_i32 | 7_i32..=i32::MAX => operand,
                } as u32;
                if ppow > 30 {
                    reg_a = 0;
                } else {
                    reg_a = reg_a / 2_i32.pow(ppow);
                }
            }
            1 => reg_b = reg_b ^ operand,
            2 => {
                reg_b = match operand {
                    4 => reg_a,
                    5 => reg_b,
                    6 => reg_c,
                    i32::MIN..=3_i32 | 7_i32..=i32::MAX => operand,
                } % 8;
            }
            3 => {
                if reg_a != 0 {
                    i = operand - 2;
                }
            }
            4 => reg_b = reg_b ^ reg_c,
            5 => {
                let tmp = match operand {
                    4 => reg_a,
                    5 => reg_b,
                    6 => reg_c,
                    i32::MIN..=3_i32 | 7_i32..=i32::MAX => operand,
                } % 8;
                print!("{tmp},");
            }
            6 => {
                let ppow: u32 = match operand {
                    4 => reg_a,
                    5 => reg_b,
                    6 => reg_c,
                    i32::MIN..=3_i32 | 7_i32..=i32::MAX => operand,
                } as u32;
                if ppow > 30 {
                    reg_b = 0;
                } else {
                    reg_b = reg_a / 2_i32.pow(ppow);
                }
            }
            7 => {
                let ppow: u32 = match operand {
                    4 => reg_a,
                    5 => reg_b,
                    6 => reg_c,
                    i32::MIN..=3_i32 | 7_i32..=i32::MAX => operand,
                } as u32;
                if ppow > 30 {
                    reg_c = 0;
                } else {
                    reg_c = reg_a / 2_i32.pow(ppow);
                }
            }
            i32::MIN..=-1_i32 | 8_i32..=i32::MAX => todo!(),
        }
        i += 2;
    }
}
