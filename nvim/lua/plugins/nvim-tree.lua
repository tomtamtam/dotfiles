return {
    "nvim-tree/nvim-tree.lua",
    dependencies = {
        "nvim-tree/nvim-web-devicons",        -- optionale Icons
    },
    cmd = { "NvimTreeToggle", "NvimTreeFocus" }, -- lazy load bei Bedarf
    keys = {
        { "<leader>e", "<cmd>NvimTreeToggle<CR>", desc = "Toggle NvimTree" },
    },
    config = function()
        require("nvim-tree").setup({
            disable_netrw = true,
            hijack_netrw = true,
            view = {
                width = 30,
                side = "left",
            },
            renderer = {
                highlight_git = true,
                icons = {
                    show = {
                        file = true,
                        folder = true,
                        folder_arrow = true,
                        git = true,
                    },
                },
            },
            filters = {
                dotfiles = false,
            },
            git = {
                enable = true,
                ignore = false,
            },
        })
    end,
}
