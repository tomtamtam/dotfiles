local function enable_transparancy()
    vim.api.nvim_set_hl(0, "Normal", { bg = "none" })
end
return {
    {
	"ellisonleao/gruvbox.nvim",
	config = function()
	    vim.cmd.colorscheme "gruvbox"
	    enable_transparancy()
	end
    },
}
