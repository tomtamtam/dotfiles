function toggle_treesitter()
    local buf = vim.api.nvim_get_current_buf()

    if vim.treesitter.highlighter.active[buf] then
        vim.treesitter.stop(buf)
        print("Treesitter disabled")
    else
        vim.treesitter.start(buf)
        print("Treesitter enabled")
    end
end

function toggle_vim_highlight()
    local syntax_enabled = vim.g.syntax_on

    if syntax_enabled == 1 then
        vim.cmd("syntax off")
        print("Vim-Syntax enabled")
    else
        vim.cmd("syntax on")
        print("Vim-Syntax enabled")
    end
end

vim.g.mapleader = " "
vim.keymap.set("n", "<leader>cd", function()
    require("nvim-tree.api").tree.toggle({ find_file = true })
end, {
    desc = "Toggle NvimTree (find file)",
})
vim.keymap.set("n", "<leader>xs", function()
    require("nvim-tree.api").tree.focus()
end, {
    desc = "Focus NvimTree",
})
vim.keymap.set("n", "<leader>h", toggle_treesitter)
vim.keymap.set("n", "<leader>vh", toggle_vim_highlight)
vim.keymap.set("n", "<leader>r", function()
    vim.cmd("LspStop clangd")
    vim.cmd("LspStart clangd")
end, { desc = "Restart LSP" })
