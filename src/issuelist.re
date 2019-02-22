let component = ReasonReact.statelessComponent("IssueList");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("This is a placeholder for the issue list.")}
    </div>,
};