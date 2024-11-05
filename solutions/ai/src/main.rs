use std::io::{self, BufRead, BufReader};
use std::{ops::{Index, Mul}, fmt::Display};

fn main() {
    let stdin = io::stdin();
    let mut reader = BufReader::new(stdin.lock());
    let mut input = String::new();
    reader.read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: usize = s.next().unwrap().parse().unwrap();
    let d: usize = s.next().unwrap().parse().unwrap();
    let mut q = vec![vec![0; d]; n];
    let mut k = vec![vec![0; n]; d];
    let mut v = vec![vec![0; d]; n];
    let mut w = vec![vec![0; 1]; n];
    for i in 0..n {
        input.clear();
        reader.read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        for j in 0..d {
            q[i][j] = s.next().unwrap().parse().unwrap();
        }
    }
    for i in 0..n {
        input.clear();
        reader.read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        for j in 0..d {
            k[j][i] = s.next().unwrap().parse().unwrap();
        }
    }
    for i in 0..n {
        input.clear();
        reader.read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        for j in 0..d {
            v[i][j] = s.next().unwrap().parse().unwrap();
        }
    }
    input.clear();
    reader.read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    for i in 0..n {
        w[i][0] = s.next().unwrap().parse().unwrap();
    }
    let ans = Matrix::from(&q).dot_product(&Matrix::from(&w)) * (Matrix::from(&k) * Matrix::from(&v));
    println!("{}", ans);
}

#[derive(Clone)]
struct Matrix(Vec<Vec<i64>>);

impl Matrix {
    fn from(vec: &Vec<Vec<i64>>) -> Self {
        Matrix(vec.clone())
    }
}

impl Mul for Matrix {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        let mut result = vec![vec![0; rhs.0[0].len()]; self.0.len()];
        for i in 0..self.0.len() {
            for j in 0..rhs.0[0].len() {
                let mut sum = 0;
                for k in 0..self.0[0].len() {
                    sum += self.0[i][k] * rhs.0[k][j];
                }
                result[i][j] = sum;
            }
        }
        Matrix(result)
    }
}

impl Index<usize> for Matrix {
    type Output = Vec<i64>;
    fn index(&self, index: usize) -> &Self::Output {
        &self.0[index]
    }
}

impl Display for Matrix {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        for row in &self.0 {
            for &val in row {
                write!(f, "{} ", val)?;
            }
            writeln!(f)?;
        }
        Ok(())
    }
}

impl Matrix {
    fn dot_product(&self, rhs: &Self) -> Self {
        let mut result = vec![vec![0; self.0[0].len()]; self.0.len()];
        for i in 0..self.0.len() {
            for j in 0..self.0[0].len() {
                result[i][j] = self.0[i][j] * rhs.0[i][0];
            }
        }
        Matrix(result)
    }
}

