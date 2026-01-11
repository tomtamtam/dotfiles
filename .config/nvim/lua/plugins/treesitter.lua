return {
  "nvim-treesitter/nvim-treesitter",
  build = ":TSUpdate",
  lazy = false,
  config = function()
    local configs = require("nvim-treesitter.config")
    
    -- Parser installieren (manuell mit :TSInstall)
    vim.g.ts_highlight_lua = true
    
    -- Highlighting aktivieren
    vim.treesitter.language.register('c', 'c')
    vim.treesitter.language.register('cpp', 'cpp')
    vim.treesitter.language.register('python', 'python')
    vim.treesitter.language.register('dart', 'dart')
    vim.treesitter.language.register('yaml', 'yaml')
    vim.treesitter.language.register('lua', 'lua')
    vim.treesitter.language.register('glsl', 'glsl')
  end,
}
