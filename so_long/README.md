*This project has been created as part of the 42 curriculum by [csamakka].*

## Description

So Long is a small 2D top-down game built using the school's graphical library, **MiniLibX**.

The goal is simple: collect all collectibles scattered across the map, then reach the exit using the shortest possible route. The player navigates a 2D grid using the W, A, S, and D keys and cannot move through walls. Every move increments a counter displayed in the shell.

Key rules:
- Collect all items before reaching the exit
- Movement is restricted to four directions: up, down, left, right
- Walls are impassable
- The number of moves is displayed in the shell after each step

## Instructions

### 1. Compile MiniLibX

The `mlx_linux` directory must be present at the root of the repository before compiling.

```bash
make mlx
```

### 2. Compile So Long

```bash
make
```

### 3. Run the game

```bash
./so_long map/map.ber
./so_long map/map2.ber
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move up |
| `S` | Move down |
| `A` | Move left |
| `D` | Move right |
| `Esc` | Quit the game |

## Resources

- [42 Cursus GitBook](https://42-cursus.gitbook.io/guide/) — General 42 project guide
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) — Unofficial MiniLibX reference
- MiniLibX introduction video available on Intra42
- Fellow 42 students
