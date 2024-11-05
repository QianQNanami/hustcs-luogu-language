use std::collections::VecDeque;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let m: usize = s.next().unwrap().parse().unwrap();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let mut map = [[-1; 100]; 100];
    for _ in 0..n{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let x: usize = s.next().unwrap().parse().unwrap();
        let y: usize = s.next().unwrap().parse().unwrap();
        let c: i32 = s.next().unwrap().parse().unwrap();
        map[x - 1][y - 1] = c;
    }
    let mut vis = [[false; 100]; 100];
    let res = bfs(&map, m);
    if res == i32::MAX {
        println!("-1");
    } else {
        println!("{}", res);
    }
}

fn bfs(
    map: &[[i32; 100]; 100],
    m: usize,
) -> i32 {
    let mut vis = [[[[i32::MAX; 2]; 2]; 100]; 100];
    let mut queue = VecDeque::new();
    let start_color = map[0][0];
    queue.push_back((0, 0, 0, true, start_color));
    vis[0][0][start_color as usize][1] = 0;
    let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    while let Some((x, y, cost, can_use_magic, color)) = queue.pop_front() {
        if x == m - 1 && y == m - 1 {
            return cost;
        }

        for &(dx, dy) in &directions {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            if nx < 0 || ny < 0 || nx >= m as i32 || ny >= m as i32 {
                continue;
            }
            let nx = nx as usize;
            let ny = ny as usize;
            let n = map[nx][ny];

            if n == -1 && can_use_magic {
                // Try changing to color 0
                let new_cost = if color != 0 { cost + 3 } else { cost + 2 };
                if vis[nx][ny][0][0] > new_cost {
                    vis[nx][ny][0][0] = new_cost;
                    queue.push_back((nx, ny, new_cost, false, 0));
                }
                // Try changing to color 1
                let new_cost = if color != 1 { cost + 3 } else { cost + 2 };
                if vis[nx][ny][1][0] > new_cost {
                    vis[nx][ny][1][0] = new_cost;
                    queue.push_back((nx, ny, new_cost, false, 1));
                }
            } else if n != -1 {
                let new_cost = if color != n { cost + 1 } else { cost };
                let magic_idx = can_use_magic as usize;
                if vis[nx][ny][n as usize][magic_idx] > new_cost {
                    vis[nx][ny][n as usize][magic_idx] = new_cost;
                    queue.push_back((nx, ny, new_cost, can_use_magic, n));
                }
            }
        }
    }

    i32::MAX
}