import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
SEGMENT_SIZE = 20
GRID_WIDTH = SCREEN_WIDTH // SEGMENT_SIZE
GRID_HEIGHT = SCREEN_HEIGHT // SEGMENT_SIZE
FPS = 10

# Colors
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
WHITE = (255, 255, 255)

# Directions
UP = (0, -1)
DOWN = (0, 1)
LEFT = (-1, 0)
RIGHT = (1, 0)

# Initialize screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Snake Game")

# Clock for controlling frame rate
clock = pygame.time.Clock()

# Font for displaying score and game over message
font = pygame.font.SysFont(None, 35)
game_over_font = pygame.font.SysFont(None, 50)

def init_game():
    """Initialize or reset the game state."""
    global snake, direction, food, score, game_over
    snake = [(10 * SEGMENT_SIZE, 12 * SEGMENT_SIZE),
             (9 * SEGMENT_SIZE, 12 * SEGMENT_SIZE),
             (8 * SEGMENT_SIZE, 12 * SEGMENT_SIZE)]
    direction = RIGHT
    food = generate_food()
    score = 0
    game_over = False

def generate_food():
    """Generate a new food position not overlapping with the snake."""
    while True:
        x = random.randint(0, GRID_WIDTH - 1) * SEGMENT_SIZE
        y = random.randint(0, GRID_HEIGHT - 1) * SEGMENT_SIZE
        if (x, y) not in snake:
            return (x, y)

def main():
    """Main game function."""
    global direction, game_over, score, food  # Fix: Declare globals
    init_game()
    running = True

    while running:
        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP and direction != DOWN:
                    direction = UP
                elif event.key == pygame.K_DOWN and direction != UP:
                    direction = DOWN
                elif event.key == pygame.K_LEFT and direction != RIGHT:
                    direction = LEFT
                elif event.key == pygame.K_RIGHT and direction != LEFT:
                    direction = RIGHT

        if not game_over:
            # Update snake position
            head = snake[0]
            new_head = (head[0] + direction[0] * SEGMENT_SIZE,
                        head[1] + direction[1] * SEGMENT_SIZE)

            # Check for collisions
            if (new_head[0] < 0 or new_head[0] >= SCREEN_WIDTH or
                new_head[1] < 0 or new_head[1] >= SCREEN_HEIGHT or
                new_head in snake):
                game_over = True
            else:
                snake.insert(0, new_head)
                if new_head == food:
                    score += 1
                    food = generate_food()
                else:
                    snake.pop()

            # Draw everything
            screen.fill(BLACK)
            for segment in snake:
                pygame.draw.rect(screen, GREEN, (segment[0], segment[1], SEGMENT_SIZE, SEGMENT_SIZE))
            pygame.draw.rect(screen, RED, (food[0], food[1], SEGMENT_SIZE, SEGMENT_SIZE))
            score_text = font.render(f"Score: {score}", True, WHITE)
            screen.blit(score_text, (10, 10))
            pygame.display.update()
            clock.tick(FPS)

        else:
            # Game over screen
            screen.fill(BLACK)
            game_over_text = game_over_font.render("Game Over", True, WHITE)
            restart_text = font.render("Press R to restart or ESC to quit", True, WHITE)
            screen.blit(game_over_text, ((SCREEN_WIDTH - game_over_text.get_width()) // 2,
                                        SCREEN_HEIGHT // 2 - 50))
            screen.blit(restart_text, ((SCREEN_WIDTH - restart_text.get_width()) // 2,
                                      SCREEN_HEIGHT // 2 + 10))
            pygame.display.update()

            # Handle game over events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_r:
                        init_game()  # Restart game
                    elif event.key == pygame.K_ESCAPE:
                        running = False

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()