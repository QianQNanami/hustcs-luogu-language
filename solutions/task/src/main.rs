struct Task {
    req: Vec<usize>,
    status: bool
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut list: Vec<Task> = Vec::new();
    for _ in 1..=n{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.trim().split_whitespace();
        let _: i32 = input.next().unwrap().parse().unwrap();
        let req: Vec<usize> = input.map(|x| x.parse().unwrap()).collect();
        let task = Task{req, status: false};
        list.push(task);
    }
    let sum = calc(0, &mut list);
    println!("{}", sum);
}

fn calc(id: usize, list:&mut Vec<Task>) -> i32 {
    let req = list[id].req.clone();
    let mut sum = 1;
    list[id].status = true;
    for i in req{
        if list[i-1].status == false{
            sum += calc(i-1, list);
        }
    }
    sum
}