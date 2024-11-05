use std::ops::Mul;
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<i128>().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let f1 = s.next().unwrap().parse::<i128>().unwrap();
    let f2 = s.next().unwrap().parse::<i128>().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let a = s.next().unwrap().parse::<i128>().unwrap();
    let b = s.next().unwrap().parse::<i128>().unwrap();
    let c = s.next().unwrap().parse::<i128>().unwrap();
    let matrix = Matrix(vec![vec![a,b,1], vec![1, 0,0], vec![0,0,1]]);
    let matrix = matrix.pow(n-2);
    let ans = matrix[0][0] * f2 + matrix[0][1] * f1 + matrix[0][2] * c;
    println!("{}", ans % 998244353);
}

use std::ops::Index;

#[derive(Clone)]
struct Matrix(Vec<Vec<i128>>);

impl Mul for Matrix {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        let mut result = vec![vec![0; rhs.0[0].len()]; self.0.len()];
        for i in 0..self.0.len() {
            for j in 0..rhs.0[0].len() {
                for k in 0..self.0[0].len() {
                    result[i][j] += (self.0[i][k] * rhs.0[k][j]) % 998244353;
                }
                result[i][j] %= 998244353;
            }
        }
        Matrix(result)
    }
}
impl Index<usize> for Matrix {
    type Output = Vec<i128>;

    fn index(&self, index: usize) -> &Self::Output {
        &self.0[index]
    }
}


impl Matrix{
    fn identity(n: usize) -> Self {
        let mut result = vec![vec![0; n]; n];
        for i in 0..n {
            result[i][i] = 1;
        }
        Matrix(result)
    }
    fn size(&self) -> usize {
        self.0.len()
    }
    fn pow(&self, n: i128) -> Self {
        let mut result = Matrix::identity(self.size());
        let mut mat = self.clone();
        let mut pow = n;
        while pow != 0{
            if pow & 1 == 1 {
                let temp = mat.clone();
                result = result * temp;
            }
            let temp = mat.clone();
            mat = mat * temp;
            pow >>= 1;
        }
        result
    }
}


