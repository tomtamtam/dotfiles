return {
    { --ssh clipboard tunneling
	'ojroques/vim-oscyank',
    },
    { --git plugin
	'tpope/vim-fugitive',
    },
    { --show css colors
	'brenoprata10/nvim-highlight-colors',
	config = function()
	    require('nvim-highlight-colors').setup({})
	end
    },
}
