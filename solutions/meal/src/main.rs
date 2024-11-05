
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let t: i32 = s.next().unwrap().parse().unwrap();
    let n: usize = s.next().unwrap().parse().unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let dep = input.split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let ti = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    let mut earliest = vec![1; n as usize];
    let mut latest = vec![0; n as usize];
    for i in 0..n {
        earliest[i] = find_dependence(&dep, &ti, i);
        print!("{} ", earliest[i as usize]);
        mod_latest(&mut latest, &dep, &ti, i, ti[i]);
    }
    let mut flag = true;
    for i in 0..n {
        let tmp = t - latest[i as usize] + 1;
        if tmp < 0 {
            flag = false;
            break;
        }
        latest[i as usize] = tmp;
    }
    if flag {
        println!();
        for i in 0..n {
            print!("{} ", latest[i as usize]);
        }
    }
}

fn find_dependence(dep: &Vec<usize>, ti: &Vec<i32>, idx: usize) -> i32 {
    if dep[idx] == 0 {
        return 1;
    }
    find_dependence(dep, ti, dep[idx] - 1) + ti[dep[idx] - 1]
}

fn mod_latest(latest: &mut Vec<i32>, dep: &Vec<usize>, ti: &Vec<i32>, idx: usize, value: i32) {
    if latest[idx] < value {
        latest[idx] = value;
    }
    if dep[idx] == 0 {
        return;
    }
    mod_latest(latest, dep, ti, dep[idx] - 1, value + ti[dep[idx] - 1]);
}
