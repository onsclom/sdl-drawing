def Settings( **kwargs ):
  return {
    'flags': ['-x', 'c', '-std=c89', '-Wall', '-Wextra', '-Werror', '-lSDL2'],
  }
