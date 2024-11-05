fn main() {
    // let input: Vec<String> = read_lines("constr.in").unwrap().map(|x| x.unwrap()).collect();
    // let first_line = input[0].clone();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i64 = s.next().unwrap().parse().unwrap();
    let a: i64 = s.next().unwrap().parse().unwrap();
    let b: i64 = s.next().unwrap().parse().unwrap();
    let base = Rectangle::new(Point::new(0, 0), Point::new(a, b));
    let mut ans=0;
    for _ in 0..n {
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let x1: i64 = s.next().unwrap().parse().unwrap();
        let y1: i64 = s.next().unwrap().parse().unwrap();
        let x2: i64 = s.next().unwrap().parse().unwrap();
        let y2: i64 = s.next().unwrap().parse().unwrap();
        let rect = Rectangle::new(Point::new(x1, y1), Point::new(x2, y2));
        if base.overlap(&rect){
            ans += rect.calc_overlap(&base);
        }
    }
    println!("{}", ans);
}


struct Point {
    x: i64,
    y: i64,
}

impl Point {
    fn new(x: i64, y: i64) -> Point {
        Point { x, y }
    }
}

struct Rectangle {
    start: Point,
    end: Point,
}

impl Rectangle {
    fn new(start: Point, end: Point) -> Rectangle {
        Rectangle { start, end }
    }
    fn overlap(&self, other: &Rectangle) -> bool {
        !(self.end.x <= other.start.x || self.start.x >= other.end.x || self.end.y <= other.start.y || self.start.y >= other.end.y)
    }
    fn calc_overlap(&self, other: &Rectangle) -> i64 {
        let x_overlap = std::cmp::min(self.end.x, other.end.x) - std::cmp::max(self.start.x, other.start.x);
        let y_overlap = std::cmp::min(self.end.y, other.end.y) - std::cmp::max(self.start.y, other.start.y);
        (x_overlap * y_overlap).abs()
    }
}