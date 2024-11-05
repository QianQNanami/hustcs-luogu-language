fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut map = std::collections::HashMap::new();
    for _ in 0..n {
        let mut str = String::new();
        for _ in 0..8{
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            str.push_str(&input);
        }
        if map.contains_key(&str) {
            let count = map.get(&str).unwrap();
            map.insert(str.clone(), count + 1);
        } else {
            map.insert(str.clone(), 1);
        }
        println!("{}", map.get(&str).unwrap());
    }
}
